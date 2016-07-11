<?php
	class Color 
	{
		public $red = 0;
		public $green = 0;
		public $blue = 0;
		function __construct(array $kwargs)
		{
			$this->red = (kwargs['rgb'] & 0xFF) >> 16;
			$this->green = (kwargs['rgb'] & 0xFF) >> 8;
			$this->blue = (kwargs['rgb'] & 0xFF);
			print("test\n");
			return ;
		}

		function __destruct()
		{
			return ;
		}

	}
	$tab = array('rgb' => 637569);
	$instance = new Color();
?>