private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	var n = readInt()
	var a = readInts()
	var b = IntArray(n)
	var p = IntArray(n)
	var cnt = 0
	for (i in 0..n-1) {
		fun BinarySearch(n: Int, i: Int): Int {
			var low = 0
			var high = n
			while (low < high) {
				var mid = low + (high - low) / 2
				if (a[b[mid]] < a[i]) low = mid + 1
				else high = mid
			}
			return low
		}
		var k = BinarySearch(cnt, i)
		b[k] = i
		p[i] = if (k > 0) b[k - 1] else -1
		if (k == cnt) cnt++
	}
	println(cnt)
	var x = b[cnt - 1]
	var res = ArrayList<Int>()
	while (x != -1) {
		res.add(a[x])
		x = p[x]
	}
	println(res.asReversed().joinToString(" "))
}
