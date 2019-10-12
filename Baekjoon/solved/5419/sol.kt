private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	class Event(var x: Int, var y: Int, var ty: Int) {}
	var tt = readInt()
	while (tt-- > 0) {
		var n = readInt()
		var e = mutableListOf<Event>()
		for (i in 0..n-1) {
			var (x, y) = readInts()
			e.add(Event(x, 0, y))
		}
		e.sortWith(compareBy({ it.ty }))
		var cnt = 0
		for (i in 0..n-1) {
			e[i].y = if (i > 0 && e[i].ty == e[i - 1].ty) e[i - 1].y else ++cnt
		}
		e.sortWith(compareBy({ -it.x }, { it.y }))
		var fenw = IntArray(n + 1, { 0 })
		fun Modify(_x: Int, v: Int) {
			var x = _x
			while (x <= n) {
				fenw[x] += v
				x += x and (-x)
			}
		}
		fun Get(_x: Int): Int {
			var x = _x
			var res = 0
			while (x > 0) {
				res += fenw[x]
				x -= x and (-x)
			}
			return res
		}
		var ans = 0L
		for (ev in e) {
			ans += Get(ev.y)
			Modify(ev.y, 1)
		}
		println(ans)
	}
}
