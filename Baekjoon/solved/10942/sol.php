<?php
	$n = (int) fgets(STDIN);
	$a = explode(" ", fgets(STDIN));
	for ($i = 0; $i < $n; $i++) {
		$a[$i] = (int) $a[$i];
	}
	for ($i = 0; $i < $n; $i++) {
		for ($j = 0; $j < $n; $j++) {
			$dp[$i][$j] = 0;
		}
	}
	for ($i = 1; $i <= $n; $i++) {
		for ($s = 0, $e = $s + $i - 1; $e < $n; $s++, $e++) {
			if ($a[$s] == $a[$e]) {
				$dp[$s][$e] = ($e - $s <= 2) ? 1 : $dp[$s + 1][$e - 1];
			}
		}
	}
	$m = (int) fgets(STDIN);
	while ($m-- > 0) {
		list($s, $e) = explode(" ", fgets(STDIN));
		$s = (int) $s;
		$e = (int) $e;
		$s--; $e--;
		echo $dp[$s][$e]."\n";
	}
?>
