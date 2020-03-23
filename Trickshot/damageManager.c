damageManager(){ //Made by DoktorSAS - Sniper Damage
	self endon( "disconnect" );
	level endon( "game_ended" );
	for(;;){	
        self waittill("damage", damage, attacker);
		if ( isSubStr(attacker getCurrentWeapon(), "cheytac") || isSubStr(attacker getCurrentWeapon(), "barrett") || isSubStr(attacker getCurrentWeapon(), "wa2000") || isSubStr(attacker getCurrentWeapon(), "fal") || isSubStr(attacker getCurrentWeapon(), "m21") || isSubStr(attacker getCurrentWeapon(), "m40a3") || isSubStr(attacker getCurrentWeapon(), "remington700") || isSubStr(attacker getCurrentWeapon(), "dragunov") || isSubStr(attacker getCurrentWeapon(), "mk14") || isSubStr(attacker getCurrentWeapon(), "l96a1") || isSubStr(self getCurrentWeapon(), "dsr") || isSubStr(attacker getCurrentWeapon(), "ballista") || isSubStr(attacker getCurrentWeapon(), "fall") || isSubStr(attacker getCurrentWeapon(), "mosin") || isSubStr(attacker getCurrentWeapon(), "msr") || isSubStr(attacker getCurrentWeapon(), "svu") || isSubStr(attacker getCurrentWeapon(), "xpr" )){
			Damage = 999;
		}else{
			self.health = self.health + damage;
		}	
	}
}
