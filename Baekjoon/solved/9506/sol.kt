private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	while (true) {
		var n = readInt()
		if (n == -1) {
			break
		}
		var a = ArrayList<Int>()
		a.add(1)
		var i = 2
		while (i * i <= n) {
			if (n % i == 0) {
				a.add(i)
				if (i * i != n) {
					a.add(n / i)
				}
			}
			i++
		}
		a.sort()
		var sum = 0
		for (x in a) {
			sum += x
		}
		if (sum == n) {
			print("${n} = ")
			println(a.joinToString(" + "))
		} else {
			println("${n} is NOT perfect.")
		}
	}
}
