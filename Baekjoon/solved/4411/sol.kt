// Wrong Answer

import java.lang.Math.abs
import java.lang.Math.floor

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	while (true) {
		var n = readInt()
		if (n == 0) break
		var a = IntArray(n)
		var sum = 0
		for (i in 0..n-1) {
			a[i] = floor((readLn().toDouble() * 100 + 0.5)).toInt()
			sum += a[i]
		}
		a.sortDescending()
		var q = sum / n
		var r = sum % n
		var ans = 0
		for (i in 0..n-1) {
			var v = q
			if (i < r) v++
			ans += abs(a[i] - v)
		}
		println(String.format("$%.2f", ans.toFloat() / 200));
	}
}
