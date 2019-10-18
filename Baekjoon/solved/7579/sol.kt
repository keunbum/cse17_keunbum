import java.lang.Math.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val C = 1e4.toInt()
	var (n, m) = readInts()
	var a = readInts()
	var b = readInts()
	var dp = IntArray(C + 1, {0})
	for (i in 0..n-1) {
		for (j in C downTo b[i]) {
			dp[j] = max(dp[j], dp[j - b[i]] + a[i])
		}
	}
	var ans = C
	for (i in 0..C) {
		if (dp[i] >= m) {
			ans = i
			break
		}
	}
	println(ans)
}
