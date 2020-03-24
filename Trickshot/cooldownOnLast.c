sscoreMonitor(){ // Function to check score /*Made by DoktorSAS*/
	self endon( "disconnect" );
	self endon( "scoreEnd" );
	level endon( "game_ended" );
	for(;;){	
		if(self.pers["score"] >= 450){ //Score in points
			self thread cooldown();
			self thread unfreeze();
			wait 0.01;
			self notify( "scoreEnd" );
		}
		wait 0.25;
	}
}
cooldown(){ //cooldown Function - 5 sec /*Made by DoktorSAS*/
	self endon("unfreezed");
	timer = 5;
	self.cooldown = self createFontString("default", 2);
	self.cooldown setPoint("CENTER", "CENTER", 0, -90);
	self freezeControls(true);
	self setBlurForPlayer( 4, 0.2 );
	onLast();
	while(true){
		timer = timer - 1;
		self.cooldown setText("Trickshot ^7Time in^1 "+ timer +"\n^7Press ^2[{+melee}] ^7to ^5unfreeze");
		wait 1;
		if(timer == 0){
			self freezeControls(false);
			self.cooldown setText("");
			self setBlurForPlayer( 0, 0.2 );
			self notify("unfreezed");
			self notify("unfreezed2");
		}
	}
}
unfreeze(){ //Unfreeze without waiting timer /*Made by DoktorSAS*/
	self endon("unfreezed2");
	self waittill("knife");
	self.cooldown setText("");
	self setBlurForPlayer( 0, 0.2 );
	self freezeControls(false);
	wait 0.25;
	self notify("unfreezed");
}
onLast(){ //Function To Set Score /*Made by DoktorSAS*/
	self.score = 1450;
	self.pers["score"] = self.score;
	self.kills = 29;
	self.deaths = randomInt(11)*2;
	self.headshots = randomInt(7)*2;
	self.pers["kills"] = self.kills;
	self.pers["deaths"] = self.deaths;
	self.pers["headshots"] = self.headshots;
	selectedFunc("You are on ^5Last");
}
