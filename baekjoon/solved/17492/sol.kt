import kotlin.system.exitProcess

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val DX = intArrayOf(1, 1, 0, -1, -1, -1, 0, 1)
	val DY = intArrayOf(0, 1, 1, 1, 0, -1, -1, -1)
	var n = readInt()
	var cnt = 0
	var a = Array(n, {readInts().toTypedArray()})
	for (i in 0..n-1) {
		for (j in 0..n-1) {
			if (a[i][j] == 2) {
				cnt++
			}
		}
	}
	fun Dfs(c: Int) {
		if (c == 1) {
			println("Possible")
			exitProcess(0)
		}
		for (x in 0..n-1) {
			for (y in 0..n-1) {
				if (a[x][y] < 2) {
					continue
				}
				for (dir in 0..7) {
					var nx = x + DX[dir]
					var ny = y + DY[dir]
					var nnx = nx + DX[dir]
					var nny = ny + DY[dir]
					if (a[nx][ny] == 2 && a[nnx][nny] == 0) {
						a[x][y] = 0
						a[nx][ny] = 0
						a[nnx][nny] = 2
						Dfs(c - 1)
						a[x][y] = 2
						a[nx][ny] = 2
						a[nnx][nny] = 0
					}
				}
			}
		}
	}
	Dfs(cnt)
	println("Impossible")
}
