private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	var n = readInt()
	var a = IntArray(n + 1)
	var deg = IntArray(n + 1, {0})
	for (i in 1..n) {
		a[i] = readInt()
		deg[a[i]]++
	}
	var b = 0
	var e = 0
	var q = IntArray(n)
	for (i in 1..n) {
		if (deg[i] == 0) q[e++] = i
	}
	while (b < e) {
		var v = q[b++]
		if (--deg[a[v]] == 0) q[e++] = a[v]
	}
	var ans = ArrayList<Int>()
	for (i in 1..n) {
		if (deg[i] > 0) ans.add(i)
	}
	println(ans.size)
	println(ans.joinToString("\n"))
}
