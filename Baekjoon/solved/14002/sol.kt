private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	var n = readInt()
	var a = readInts()
	var dp = IntArray(n, {1})
	var p = IntArray(n, {-1})
	for (i in 0..n-1) {
		for (j in 0..i-1) {
			if (a[j] < a[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1
				p[i] = j
			}
		}
	}
	var x = 0
	for (i in 1..n-1) {
		if (dp[x] < dp[i]) {
			x = i
		}
	}
	println(dp[x])
	var res = ArrayList<Int>()
	while (x != -1) {
		res.add(a[x])
		x = p[x]
	}
	println(res.asReversed().joinToString(" "))
}
