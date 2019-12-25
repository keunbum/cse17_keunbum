private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	var n = readInt()
	var a = Array(n, {readInts().toTypedArray()})
	var dp = Array(n, {LongArray(n, {0L})})
	dp[0][0] = 1L
	for (i in 0..n-1) {
		for (j in 0..n-1) {
			if (a[i][j] == 0) continue
			if (i + a[i][j] < n) dp[i + a[i][j]][j] += dp[i][j];
			if (j + a[i][j] < n) dp[i][j + a[i][j]] += dp[i][j];
		}
	}
	println(dp[n - 1][n - 1])
}
