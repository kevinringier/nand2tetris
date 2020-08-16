package assembler

import java.io.{BufferedWriter, File, FileWriter}

import assembler.code.Code
import assembler.common.AssemblerHelper.StringHelper
import assembler.common.Writable
import assembler.parser.Parser
import assembler.symbol.table.SymbolTable

// "D:\\dev\\nand2tetris\\projects\\06\\add\\Add.asm"
// "D:\\dev\\nand2tetris\\projects\\06\\max\\Max.asm"
// "D:\\dev\\nand2tetris\\projects\\06\\pong\\Pong.asm"
// "D:\\dev\\nand2tetris\\projects\\06\\rect\\Rect.asm"

object Assembler {
  def main(args: Array[String]): Unit = {
    val filename: String = args(0)
    val lines = Parser(filename).toList
    val commands = lines
      .filter(Parser.filterEmptyLines)
      .filter(Parser.filterLineComments)
      .map(Parser.trimComments)
      .map(_.trim)
      .map(Parser.parseCommand)
    val translator = Code(SymbolTable(commands))
    val output = commands
      .collect[Writable] { case c: Writable => c.asInstanceOf[Writable] }
      .map(translator.translateCommand)

    writeFile(filename.withHackExtension, output)
  }

  private def writeFile(filename: String, lines: Seq[String]): Unit = {
    val file = new File(filename)
    val bw = new BufferedWriter(new FileWriter(file))
    for (line <- lines) {
      bw.write(line + "\n")
    }
    bw.close()
  }
}
