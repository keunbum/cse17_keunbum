private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	var n = readInt()
	var dp = IntArray(n + 1)
	dp[1] = 0
	var p = IntArray(n + 1)
	for (i in 2..n) {
		var f = i - 1
		dp[i] = dp[f] + 1
		p[i] = f
		f = i / 2
		if ((i and 1) == 0 && dp[i] > dp[f] + 1) {
			dp[i] = dp[f] + 1
			p[i] = f
		}
		f = i / 3;
		if (i % 3 == 0 && dp[i] > dp[f] + 1) {
			dp[i] = dp[f] + 1
			p[i] = f
		}
	}
	println(dp[n])
	var res = ArrayList<Int>()
	p[1] = 0
	while (n != 0) {
		res.add(n)
		n = p[n]
	}
	println(res.joinToString(" "))
}
