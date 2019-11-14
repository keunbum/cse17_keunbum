import java.lang.Math.min
import java.lang.Math.abs


private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	var n = readInt()
	var p = readInts()
	var g = Array<MutableList<Int>>(n, { i -> mutableListOf() })
	for (i in 0..n-1) {
		var t = readInts()
		for (j in 1..t[0]) {
			g[i].add(t[j] - 1)
		}
	}
	val inf = 1e9.toInt()
	var ans = inf
	for (t in 1..((1 shl n) - 1)) {
		var foo = 0
		var c = IntArray(n)
		for (i in 0..n-1) {
			c[i] = (t shr i) and 1
			foo += if (c[i] == 1) p[i] else -p[i]
		}
		var cnt = 0
		var was = BooleanArray(n, {false})
		fun Dfs(v: Int) {
			was[v] = true
			for (u in g[v]) {
				if (!was[u] && c[v] == c[u]) {
					Dfs(u)
				}
			}
		}
		for (i in 0..n-1) {
			if (!was[i]) {
				Dfs(i)
				cnt++
			}
		}
		if (cnt == 2) {
			ans = min(ans, abs(foo))
		}
	}
	println(if (ans == inf) -1 else ans)
}
