changeClassAnytime(){ //Made By DoktorSAS
	self endon("disconnect");
	level endon( "game_ended" );
	self waittil("spawned_player"); //Don't remove this
	for(;;){
		oldclass = self.pers["class"];
		wait 0.05;
		if(self.pers["class"] != oldclass){
			self maps\mp\gametypes\_class::giveloadout(self.pers["team"],self.pers["class"]);
			oldclass = self.pers["class"];
		}
	}
}
