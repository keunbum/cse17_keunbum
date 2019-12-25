private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private fun gcd(_a : Int, _b: Int): Int {
	var a = _a
	var b = _b
	while (a > 0) {
		var t = b % a
		b = a
		a = t
	}
	return b
}

fun main(args: Array<String>) {
	var tt = readInt()
	while (tt-- > 0) {
		var a = readInts()
		var n = a[0]
		var ans = 0L
		for (i in 1..n) {
			for (j in i+1..n) {
				ans += gcd(a[i], a[j]);
			}
		}
		println(ans)
	}
}
