#!/usr/bin/php
<?PHP
while (1)
{
	echo "Entrez un nombre: ";
	$handle = fopen ("php://stdin","r");
	$nb_pile = fgets($handle);
	if (feof($handle))
	{
		print (" ^D\n");
		exit();
	}
	$nb_pile = substr($nb_pile, 0, strlen($nb_pile) - 1);
	if (!(is_numeric($nb_pile)))
		echo "'$nb_pile' n'est pas un chiffre\n";
	else
	{
		if (($nb_pile % 2) == 0)
			echo "Le chiffre $nb_pile est Pair\n";
		else
			echo "Le chiffre $nb_pile est Impair\n";
	}
}
?>