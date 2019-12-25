import java.io.*
import java.util.*
import java.math.*
 
fun main() {
	val inputStream = System.`in`
	val outputStream = System.out
	val `in` = Main.InputReader(inputStream)
	val out = PrintWriter(outputStream)
	val solver = Main.Task()
	solver.solve(`in`.nextInt(), `in`, out)
	out.close()
}
 
object Main {
	internal class Task {
		fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
			for (qq in 1..testNumber) {
				var n = `in`.nextInt()
				var e = mutableListOf<Event>()
				for (i in 0..n-1) {
					var x = `in`.nextInt()
					var y = `in`.nextInt()
					e.add(Event(x, 0, y))
				}
				e.sortWith(compareBy({ it.ty }))
				var cnt = 0
				for (i in 0..n-1) {
					e[i].y = if (i > 0 && e[i].ty == e[i - 1].ty) e[i - 1].y else ++cnt
				}
				e.sortWith(compareBy({ -it.x }, { it.y }))
				var fenw = IntArray(n + 1, { 0 })
				var ans = 0L
				for (ev in e) {
					ans += Get(fenw, ev.y)
					Modify(fenw, n, ev.y, 1)
				}
				out.println(ans)
			}
		}
	}
	private fun Modify(fenw: IntArray, n: Int, _x: Int, v: Int) {
		var x = _x
		while (x <= n) {
			fenw[x] += v
			x += x and (-x)
		}
	}
	private fun Get(fenw: IntArray, _x: Int): Int {
		var x = _x
		var res = 0
		while (x > 0) {
			res += fenw[x]
			x -= x and (-x)
		}
		return res
	}
	internal class Event(var x: Int, var y: Int, var ty: Int) {
	}
	internal class InputReader(stream: InputStream) {
		var reader: BufferedReader
		var tokenizer: StringTokenizer? = null

		init {
			reader = BufferedReader(InputStreamReader(stream), 32768)
			tokenizer = null
		}

		operator fun next(): String {
			while (tokenizer == null || !tokenizer!!.hasMoreTokens()) {
				try {
					tokenizer = StringTokenizer(reader.readLine())
				} catch (e: IOException) {
					throw RuntimeException(e)
				}
			}
			return tokenizer!!.nextToken()
		}

		fun nextInt(): Int {
			return Integer.parseInt(next())
		}
	}
}
