import java.lang.Math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val inf = 1e9.toInt();
	var (n, m) = readInts()
	var a = Array(n, { IntArray(n, { inf }) })
	while (m-- > 0) {
		var (x, y) = readInts()
		x--
		y--
		a[x][y] = 1
		a[y][x] = 1
	}
	for (k in 0..n-1) {
		for (i in 0..n-1) {
			for (j in 0..n-1) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j])
			}
		}
	}
	var mn = inf
	var mi = 0
	for (i in 0..n-1) {
		var foo = 0
		for (j in 0..n-1) {
			if (i != j) {
				foo += a[i][j]
			}
		}
		if (foo < mn) {
			mn = foo
			mi = i
		}
	}
	println(++mi)
}
