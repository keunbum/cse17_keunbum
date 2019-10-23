private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val N = 55
	var s = readLn()
	var stk = IntArray(N)
	var stk_c = CharArray(N)
	var top = 0
	for (c in s) {
		if (c != ')') {
			stk[top] = 1;
			stk_c[top] = c
			top++
		} else {
			var v = 0
			while (stk_c[--top] != '(') {
				v += stk[top]
			}
			stk[top - 1] = (stk_c[top - 1] - '0') * v
		}
	}
	var ans = 0
	while (--top >= 0) {
		ans += stk[top]
	}
	println(ans)
}
