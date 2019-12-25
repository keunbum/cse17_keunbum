private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	var n = readInt()
	var ans = 0
	fun IsHan(n: Int): Boolean {
		if (n < 100) {
			return true
		}
		var a = n / 100
		var b = (n / 10) % 10
		var c = n % 10
		return b + b == a + c
	}
	for (i in 1..n) {
		ans += if (IsHan(i)) 1 else 0
	}
	println(ans)
}
