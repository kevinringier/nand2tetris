package assembler.common

sealed trait Writable
sealed trait Command
final case class A_COMMAND(symbol: String) extends Command with Writable
final case class C_COMMAND(dest: String, comp: String, jump: String) extends Command with Writable
final case class L_COMMAND(symbol: String) extends Command

sealed trait InstructionType
case object A_INSTRUCTION extends InstructionType
case object C_INSTRUCTION extends InstructionType
