package assembler.parser

import assembler.common.{A_COMMAND, C_COMMAND, Command, L_COMMAND}

import scala.annotation.tailrec
import scala.io.Source

object Parser {
  def apply(filepath: String): Iterator[String] = {
    val bufferedSource = Source.fromFile(filepath)
    val lines = bufferedSource.getLines

    lines
  }

  def filterLineComments(line: String): Boolean = line(0) != '/' && line(1) != '/'

  def filterEmptyLines(line: String): Boolean = line != ""

  def trimComments(line: String): String = {
    for (temp <- 0 until line.length - 1) {
      if (line(temp) == '/' && line(temp + 1) == '/') {
        return line.substring(0, temp - 1)
      }
    }

    line
  }

  def parseCommand(command: String): Command = {
    command.head match {
      case '@' => A_COMMAND(command.tail)
      case '(' => L_COMMAND(command.tail.dropRight(1))
      case _ => parseCCommand(command)
    }
  }

  private def parseCCommand(command: String): C_COMMAND = {
    var dest, comp, jump = ""

    @tailrec
    def recursiveParse(command: String, index: Int): Unit = {
      if (index < command.length) {
        command(index) match {
          case '=' =>
            val subCommands = command.split('=')
            dest = subCommands(0)
            recursiveParse(subCommands(1), 0)
          case ';' =>
            val subCommands = command.split(';')
            comp = subCommands(0)
            jump = subCommands(1)
          case _ => recursiveParse(command, index + 1)
        }
      } else {
        comp = command
      }
    }

    recursiveParse(command, 0)

    C_COMMAND(dest, comp, jump)
  }
}
