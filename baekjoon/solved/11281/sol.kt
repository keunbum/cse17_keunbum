import java.lang.Math.abs

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private fun T(x: Int): Int = (abs(x) - 1) * 2 + if (x < 0) 1 else 0

fun main(args: Array<String>) {
  var (n, m) = readInts()
  var g = Array<MutableList<Int>>(n + n, { _ -> mutableListOf() })
  var g_rev = Array<MutableList<Int>>(n + n, { _ -> mutableListOf() })
  while (m-- > 0) {
    var (foo, bar) = readInts()
    var x = T(foo)
    var y = T(bar)
    g[x xor 1].add(y)
    g_rev[y].add(x xor 1)
    g[y xor 1].add(x)
    g_rev[x].add(y xor 1)
  }
  var was = BooleanArray(n + n, {false})
  var order = ArrayList<Int>()
  fun Dfs1(v: Int) {
    was[v] = true
    for (u in g[v]) {
      if (!was[u]) {
        Dfs1(u)
      }
    }
    order.add(v)
  }
  for (i in 0..n+n-1) {
    if (!was[i]) {
		  Dfs1(i)
		}
  }
  var cnt = 0
  var c = IntArray(n + n, {-1})
  fun Dfs2(v: Int) {
    for (u in g_rev[v]) {
      if (c[u] == -1) {
        c[u] = c[v]
        Dfs2(u)
      }
    }
  }
  for (i in n+n-1 downTo 0) {
    var v = order[i]
    if (c[v] == -1) {
      c[v] = cnt++
      Dfs2(v)
    }
  }
  for (i in 0..n-1) {
    var e = i shl 1
    if (c[e] == c[e xor 1]) {
      println(0)
      return
    }
  }
  println(1)
  var res = IntArray(n)
  for (i in 0..n-1) {
    var e = i shl 1
    res[i] = if (c[e] > c[e xor 1]) 1 else 0
  }
  println(res.joinToString(" "))
}
