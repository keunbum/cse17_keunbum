<?php
	fscanf(STDIN, "%d", $n);
	for ($i = 0; $i < 9; $i++) {
		fprintf(STDOUT, "%d * %d = %d\n", $n, $i + 1, $n * ($i + 1));
	}
?>
