<?php
	$a = [];
	for ($i = 1; $i < 6; $i++) {
		$pos = strpos(fgets(STDIN), "FBI");
		if ($pos !== false) {
			$a[] = $i;
		}
	}
	echo (sizeof($a) == 0 ? "HE GOT AWAY!" : implode(' ', $a))."\n";
?>
