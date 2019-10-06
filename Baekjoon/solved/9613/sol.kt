private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	fun Gcd(a: Int, b: Int): Int {
		return if (a == 0) b else Gcd(b % a, a)
	}
	var tt = readInt()
	while (tt-- > 0) {
		var a = readInts()
		var n = a[0]
		var ans = 0L
		for (i in 1..n) {
			for (j in i+1..n) {
				ans += Gcd(a[i], a[j]);
			}
		}
		println(ans)
	}
}
