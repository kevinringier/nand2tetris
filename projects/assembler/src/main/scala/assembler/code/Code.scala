package assembler.code

import assembler.common.AssemblerHelper._
import assembler.common.{A_COMMAND, A_INSTRUCTION, C_COMMAND, C_INSTRUCTION, Writable}
import assembler.symbol.table.SymbolTable

class Code(private val symbolTable: SymbolTable) {
  def translateCommand[T <: Writable](command: T): String = {
    command match {
      case c: A_COMMAND => translateACommand(c)
      case c: C_COMMAND => translateCInstruction(c)
    }
  }

  private def translateACommand(command: A_COMMAND): String = {
    command.symbol
      .toIntOption
      .fold(symbolTable.processKey(command.symbol))(x => x)
      .intToBinaryString(A_INSTRUCTION)
  }

  private def translateCInstruction(command: C_COMMAND): String = {
    import CodeMappings._

    val dest = destMappings.getOrElse(command.dest, 0)
    val jump = jumpMappings.getOrElse(command.jump, 0)
    val comp = compMappings.getOrElse(command.comp, 0)

    (dest + jump + comp).intToBinaryString(C_INSTRUCTION)
  }
}

object Code {
  def apply(symbolTable: SymbolTable): Code = {
    new Code(symbolTable)
  }
}

object CodeMappings {
  val destMappings = Map(
    "" -> 0,
    "M" -> 8,
    "D" -> 16,
    "MD" -> 24,
    "A" -> 32,
    "AM" -> 40,
    "AD" -> 48,
    "AMD" -> 56
  )

  val jumpMappings = Map(
    "" -> 0,
    "JGT" -> 1,
    "JEQ" -> 2,
    "JGE" -> 3,
    "JLT" -> 4,
    "JNE" -> 5,
    "JLE" -> 6,
    "JMP" -> 7
  )

  val compMappings = Map(
    "0" -> 2688,
    "1" -> 4032,
    "-1" -> 3712,
    "D" -> 768,
    "A" -> 3072,
    "!D" -> 832,
    "!A" -> 3136,
    "-D" -> 960,
    "-A" -> 3264,
    "D+1" -> 1984,
    "A+1" -> 3520,
    "D-1" -> 896,
    "A-1" -> 3200,
    "D+A" -> 128,
    "D-A" -> 1216,
    "A-D" -> 448,
    "D&A" -> 0,
    "D|A" -> 1344,
    "M" -> 7168,
    "!M" -> 7232,
    "-M" -> 7360,
    "M+1" -> 7616,
    "M-1" -> 7296,
    "D+M" -> 4224,
    "D-M" -> 5312,
    "M-D" -> 4544,
    "D&M" -> 4096,
    "D|M" -> 5440,
  )
}

