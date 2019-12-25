private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val N = 1e6.toInt()
	var is_p = BooleanArray(N + 1, {true})
	for (i in 2..N) {
		if (!is_p[i]) continue
		var j = i + i
		while (j <= N) {
			is_p[j] = false
			j += i
		}
	}
	while (true) {
		var n = readInt()
		if (n == 0) break
		var i = 3
		while (i <= n / 2) {
			var j = n - i
			if (is_p[i] && is_p[j]) {
				println("${n} = ${i} + ${j}")
				break
			}
			i += 2
		}
	}
}
