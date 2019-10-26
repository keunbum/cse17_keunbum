private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val N = 1e5.toInt()
	var a = IntArray(N + 1, {-1})
	var cnt = IntArray(N + 1)
	var q = IntArray(N + 1)
	var (st, en) = readInts()
	var b = 0
	var e = 0
	a[st] = 0
	cnt[st] = 1
	q[e++] = st
	while (b < e) {
		var v = q[b++]
		if (v == en) break
		for (i in -1..1) {
			var u = if (i == 0) v + v else v + i
			if (u >= 0 && u <= N) {
				if (a[u] == -1) {
					a[u] = a[v] + 1
					q[e++] = u
				}
				if (a[u] == a[v] + 1) {
					cnt[u] += cnt[v]
				}
			}
		}
	}
	println("${a[en]}\n${cnt[en]}")
}
