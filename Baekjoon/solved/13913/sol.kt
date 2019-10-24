private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val N = 1e5.toInt()
	var q = IntArray(N + N + 5)
	var a = IntArray(N + 1, {-1})
	var p = IntArray(N + 1, {-1})
	var (st, en) = readInts()
	var b = 0
	var e = 0
	q[e++] = st
	a[st] = 0
	while (true) {
		var v = q[b++]
		if (v == en) {
			break
		}
		fun F(u: Int) {
			if (u < 0 || u > N || a[u] >= 0) {
				return
			}
			a[u] = a[v] + 1
			q[e++] = u
			p[u] = v
		}
		F(v - 1)
		F(v + 1)
		F(v + v)
	}
	println(a[en])
	var res = ArrayList<Int>()
	while (en != -1) {
		res.add(en)
		en = p[en]
	}
	println(res.reversed().joinToString(" "))
}
