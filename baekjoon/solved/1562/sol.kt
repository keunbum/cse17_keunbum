private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

val MD = 1e9.toInt()

private fun Add(a: Int, b: Int): Int {
  var res = a + b
  if (res >= MD) res -= MD
  return res
}

fun main(args: Array<String>) {
  var n = readInt()
  var dp = Array(n + 1, { Array(10, { IntArray(1024, { 0 }) }) })
  for (i in 1..9) {
    dp[1][i][1 shl i] = 1
  }
  for (i in 2..n) {
    for (j in 0..9) {
      for (t in 1..1023) {
	if (j - 1 >= 0 && (t and (1 shl (j - 1))) != 0) {
	  dp[i][j][t or (1 shl j)] = Add(dp[i][j][t or (1 shl j)], dp[i - 1][j - 1][t]);
	}
	if (j + 1 < 10 && (t and (1 shl (j + 1))) != 0) {
	  dp[i][j][t or (1 shl j)] = Add(dp[i][j][t or (1 shl j)], dp[i - 1][j + 1][t]);
	}
      }
    }
  }
  var ans = 0
  for (i in 0..9) {
    ans = Add(ans, dp[n][i][1023]);
  }
  println(ans)
}
