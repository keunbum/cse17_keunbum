private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private fun gcd(a : Int, b: Int): Int = if (a == 0) b else gcd(b % a, a)

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
