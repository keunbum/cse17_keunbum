<?php
	$n = (int) fgets(STDIN);
	$ans = 0;
	while ($n-- > 0) {
		$ok = True;
		$s = rtrim(fgets(STDIN));
		$chk = array_fill(0, 128, False);
		$l = strlen($s);
		for ($i = 0; $i < $l; $i++) {
			if ($chk[ord($s[$i])] && $s[$i - 1] != $s[$i]) {
				$ok = False;
				break;
			}
			$chk[ord($s[$i])] = True;
		}
		$ans += (int) $ok;
	}
	echo $ans."\n";