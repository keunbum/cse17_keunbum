private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	class Student(var x: Int, var y: Int, var z: Int, var s: String)
	var n = readInt()
	var a = ArrayList<Student>()
	for (i in 0..n-1) {
		var (s, x, y, z) = readStrings()
		a.add(Student(-x.toInt(), y.toInt(), -z.toInt(), s))
	}
	var ans = a.sortedWith(compareBy({it.x}, {it.y}, {it.z}, {it.s})).map { it.s }
	println(ans.joinToString("\n"))
}
