package assembler.common

import scala.annotation.tailrec

object AssemblerHelper {
  implicit class StringHelper(s: String) {
    def isInt: Boolean = {
      s.toIntOption.fold(false)(_ => true)
    }

    def withHackExtension: String = {
      s.split('.').head.concat(".hack")
    }
  }

  implicit class IntHelper(i: Int) {
    def intToBinaryString(commandType: InstructionType): String = {
      val partialBits = divideBy2(i, Nil)
      val bits = appendMSBits(partialBits, commandType)

      bits.mkString
    }
  }

  @tailrec
  private def divideBy2(i: Int, bits: List[Int]): List[Int] = {
    i match {
      case 0 => bits
      case _ => divideBy2(i / 2, (i % 2) :: bits)
    }
  }

  @tailrec
  private def appendMSBits(bits: List[Int], commandType: InstructionType): List[Int] = {
    bits.length match {
      case i if 13 to 15 contains i => commandType match {
        case A_INSTRUCTION => appendMSBits(0 :: bits, commandType)
        case C_INSTRUCTION => appendMSBits(1 :: bits, commandType)
      }
      case 16 => bits
      case _  => appendMSBits(0 :: bits, commandType)
    }
  }
}
