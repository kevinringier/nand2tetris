package assembler.symbol.table

import assembler.common.{Command, L_COMMAND}

import scala.collection.immutable
import scala.collection.immutable.HashMap
import scala.collection.mutable

class SymbolTable(args: (String, Int)*) extends mutable.HashMap[String, Int] {
  this ++= args
  var currentMemoryAddress = 0

  def processKey(key: String): Int = {
    this.get(key).fold(
      this.addOne((key, readCurrentMemoryAddress()))(key)
    )(v => v)
  }

  private def readCurrentMemoryAddress(): Int = {
    if (currentMemoryAddress == 0) currentMemoryAddress = 16
    else currentMemoryAddress += 1

    currentMemoryAddress
  }
}

object SymbolTable {
  def apply(commands: List[Command]): SymbolTable = {
    val symbolTable = new SymbolTable(initSymbolTable.toSeq: _*)
    buildSymbolTable(commands, symbolTable)

    symbolTable
  }

  private def buildSymbolTable(commands: List[Command], table: SymbolTable): Unit = {
    var romAddress = 0
    commands.foreach {
      case L_COMMAND(c) if !table.keySet.contains(c) =>
        table.addOne((c, romAddress))
      case _ => romAddress += 1
    }
  }

  val initSymbolTable: HashMap[String, Int] =
    immutable.HashMap(
      "SP" -> 0x0000, "LCL" -> 0x0001,
      "ARG" -> 0x0002, "THIS" -> 0x0003,
      "THAT" -> 0x0004, "R0" -> 0x0000,
      "R1" -> 0x0001, "R2" -> 0x0002,
      "R3" -> 0x0003, "R4" -> 0x0004,
      "R5" -> 0x0005, "R6" -> 0x0006,
      "R7" -> 0x0007, "R8" -> 0x0008,
      "R9" -> 0x0009, "R10" -> 0x000a,
      "R11" -> 0x000b, "R12" -> 0x000c,
      "R13" -> 0x000d, "R14" -> 0x000e,
      "R15" -> 0x000f, "SCREEN" -> 0x4000,
      "KBD" -> 0x6000
    )
}
