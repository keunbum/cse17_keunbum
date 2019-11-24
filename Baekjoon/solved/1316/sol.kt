private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	var n = readInt()
	var ans = 0
	while (n-- > 0) {
		var s = readLn()
		var l = s.length
		var ok = true
		var chk = BooleanArray(128, { false })
		for (i in 0..l-1) {
			if (chk[s[i].toInt()] && s[i - 1] != s[i]) {
				ok = false
				break
			}
			chk[s[i].toInt()] = true
		}
		if (ok) {
			ans++;
		}
	}
	println(ans)
}
