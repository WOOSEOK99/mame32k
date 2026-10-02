/* MULTIPLAYER GAME HACKS */
switch(game)
{
case kof2000_6p:
{
	int energy1 = cpunum_read_byte(0, 0x108239) | 0x0F;
	int energy2 = cpunum_read_byte(0, 0x108439) | 0x0F;
	if( (cpunum_read_byte(0, 0x10A7F9) == 0 && cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF && cpunum_read_byte(0, 0x10A7FC) == 0xFF) ||
		(cpunum_read_byte(0, 0x10A80E) == 0 && cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF && cpunum_read_byte(0, 0x10A811) == 0xFF) ||
		(cpunum_read_byte(0, 0x10A7F9) == 0 && energy1 == 0xFF) ||
		(cpunum_read_byte(0, 0x10A80E) == 0 && energy2 == 0xFF) ||
		cpunum_read_byte(0, 0x10A805) == 0xFF ||
		cpunum_read_byte(0, 0x10A81A) == 0xFF )
		init = 0;

	if(init == 0)
	{
		if(kPlayers == 4 || kPlayers == 2)
		{
			if((cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,0,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,0,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF))
				change_position(1,0,2,3,4,5);
		}
		else if(kPlayers == 5)
		{
			if((cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,2,0,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,2,0,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF))
				change_position(0,1,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF))
				change_position(1,0,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF))
				change_position(1,2,0,4,3,5);
		}
		else if(kPlayers == 3 || kPlayers >= 6)
		{
			if((cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,2,0,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(0,1,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,0,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,2,0,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF))
				change_position(0,1,2,4,5,3);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF))
				change_position(1,0,2,4,5,3);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF))
				change_position(1,2,0,4,5,3);
		}
		
		if( cpunum_read_byte(0, 0x10A7E6) == 0x60 &&
			cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF && cpunum_read_byte(0, 0x10A7FC) != 0xFF && cpunum_read_byte(0, 0x10A7FD) != 0xFF &&
			cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF && cpunum_read_byte(0, 0x10A811) != 0xFF && cpunum_read_byte(0, 0x10A812) != 0xFF &&
			cpunum_read_byte(0, 0x10A805) != 0xFF && cpunum_read_byte(0, 0x10A81A) != 0xFF )
		{
			init = 1;
		}
	}
	else
	{
		p1_1st = cpunum_read_byte(0, 0x10A802);
		p1_2nd = cpunum_read_byte(0, 0x10A803);
		p1_3rd = cpunum_read_byte(0, 0x10A804);
		p2_1st = cpunum_read_byte(0, 0x10A817);
		p2_2nd = cpunum_read_byte(0, 0x10A818);
		p2_3rd = cpunum_read_byte(0, 0x10A819);
		
		if( cpunum_read_byte(0, 0x10A7E6) == 0x60 )
		{
			if(cpunum_read_byte(0, 0x10A7F9) == 0 && cpunum_read_byte(0, 0x10A80E) == 0)
				kof_swap(p1_1st, p2_1st);
			else if(cpunum_read_byte(0, 0x10A7F9) == 0 && cpunum_read_byte(0, 0x10A80E) == 1)
				kof_swap(p1_1st, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A7F9) == 0 && cpunum_read_byte(0, 0x10A80E) == 2)  
				kof_swap(p1_1st, p2_3rd);
			else if(cpunum_read_byte(0, 0x10A7F9) == 1 && cpunum_read_byte(0, 0x10A80E) == 0)  
				kof_swap(p1_2nd, p2_1st);
			else if(cpunum_read_byte(0, 0x10A7F9) == 1 && cpunum_read_byte(0, 0x10A80E) == 1)  
				kof_swap(p1_2nd, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A7F9) == 1 && cpunum_read_byte(0, 0x10A80E) == 2)  
				kof_swap(p1_2nd, p2_3rd);
			else if(cpunum_read_byte(0, 0x10A7F9) == 2 && cpunum_read_byte(0, 0x10A80E) == 0)  
				kof_swap(p1_3rd, p2_1st);
			else if(cpunum_read_byte(0, 0x10A7F9) == 2 && cpunum_read_byte(0, 0x10A80E) == 1)  
				kof_swap(p1_3rd, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A7F9) == 2 && cpunum_read_byte(0, 0x10A80E) == 2)  
				kof_swap(p1_3rd, p2_3rd);
		}
	}
	break;
}
case kof2001_8p:
{
    if( (cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF && cpunum_read_byte(0, 0x10A7E9) == 0xFF) ||
        (cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF && cpunum_read_byte(0, 0x10A80F) == 0xFF) )
		init = 0;

    if(init == 0)
	{
        if(kPlayers == 4 || kPlayers == 2)
		{
			if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,0,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,0,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,0,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,0,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position(1,0,2,3,4,5);
		}
		else if(kPlayers == 3)
		{
			if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF))
				change_position(1,0,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF))
				change_position(1,0,3,2,4,5);
		}
		else if(kPlayers == 5)
		{
			if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,2,0,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,2,0,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,2,0,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,2,0,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(0,1,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,0,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,2,0,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,2,0,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position(0,1,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position(1,0,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position(1,2,0,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position(1,2,0,4,3,5);
		}
		else if(kPlayers == 6)
		{
			if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,2,0,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,2,0,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(0,1,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,0,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,2,0,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,2,0,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(0,1,2,4,5,3);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,0,2,4,5,3);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,2,0,4,5,3);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position(1,2,0,4,5,3);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position(0,1,2,4,5,3);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position(1,0,2,4,5,3);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position(1,2,0,4,5,3);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position(1,2,0,4,5,3);
		}
		else if(kPlayers == 7)
		{
			if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(0,1,1,1,3,1,1,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(1,0,1,1,3,1,1,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(1,1,0,1,3,1,1,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(1,1,1,0,3,1,1,1);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(0,1,1,1,1,3,1,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(1,0,1,1,1,3,1,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(1,1,0,1,1,3,1,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(1,1,1,0,1,3,1,1);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(0,1,1,1,1,1,3,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(1,0,1,1,1,1,3,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(1,1,0,1,1,1,3,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(1,1,1,0,1,1,3,1);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position2(0,1,1,1,1,1,3,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position2(1,0,1,1,1,1,3,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position2(1,1,0,1,1,1,3,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position2(1,1,1,0,1,1,3,1);
		}
		else if(kPlayers >= 8)
		{
			if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(0,1,1,1,3,1,1,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(1,0,1,1,3,1,1,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(1,1,0,1,3,1,1,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(1,1,1,0,3,1,1,1);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(0,1,1,1,1,3,1,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(1,0,1,1,1,3,1,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(1,1,0,1,1,3,1,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(1,1,1,0,1,3,1,1);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(0,1,1,1,1,1,3,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(1,0,1,1,1,1,3,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(1,1,0,1,1,1,3,1);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF))
				change_position2(1,1,1,0,1,1,3,1);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position2(0,1,1,1,1,1,1,3);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position2(1,0,1,1,1,1,1,3);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position2(1,1,0,1,1,1,1,3);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF && cpunum_read_byte(0, 0x10A7E8) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF && cpunum_read_byte(0, 0x10A80E) != 0xFF))
				change_position2(1,1,1,0,1,1,1,3);
		}
		
		if( cpunum_read_byte(0, 0x10A7D2) == 0x60 && cpunum_read_byte(0, 0x10A7D3) == 0x32 ) 
		{
			init = 1;
		}
	}
	else
	{
		if( cpunum_read_byte(0, 0x10A7D2) == 0x60 )
		{
			p1_1st = cpunum_read_byte(0, 0x10A7EE);
			p1_2nd = cpunum_read_byte(0, 0x10A7EF);
			p1_3rd = cpunum_read_byte(0, 0x10A7F0);
			p1_4th = cpunum_read_byte(0, 0x10A7F1);
			p2_1st = cpunum_read_byte(0, 0x10A814);
			p2_2nd = cpunum_read_byte(0, 0x10A815);
			p2_3rd = cpunum_read_byte(0, 0x10A816);
			p2_4th = cpunum_read_byte(0, 0x10A817);
			p1_1c = cpunum_read_byte(0, 0x10A7E6);
			p1_2c = cpunum_read_byte(0, 0x10A7E7);
			p1_3c = cpunum_read_byte(0, 0x10A7E8);
			p1_4c = cpunum_read_byte(0, 0x10A7E9);
			p2_1c = cpunum_read_byte(0, 0x10A80F);
			p2_2c = cpunum_read_byte(0, 0x10A80E);
			p2_3c = cpunum_read_byte(0, 0x10A80D);
			p2_4c = cpunum_read_byte(0, 0x10A80C);
			
			if(cpunum_read_byte(0, 0x10A7F3) == 0 && cpunum_read_byte(0, 0x10A819) == 0)
				kof_swap2(p1_1st, p2_1st);
			else if(cpunum_read_byte(0, 0x10A7F3) == 0 && cpunum_read_byte(0, 0x10A819) == 1)
				kof_swap2(p1_1st, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A7F3) == 0 && cpunum_read_byte(0, 0x10A819) == 2)  
				kof_swap2(p1_1st, p2_3rd);
			else if(cpunum_read_byte(0, 0x10A7F3) == 0 && cpunum_read_byte(0, 0x10A819) == 3)  
				kof_swap2(p1_1st, p2_4th);
			else if(cpunum_read_byte(0, 0x10A7F3) == 1 && cpunum_read_byte(0, 0x10A819) == 0)  
				kof_swap2(p1_2nd, p2_1st);
			else if(cpunum_read_byte(0, 0x10A7F3) == 1 && cpunum_read_byte(0, 0x10A819) == 1)  
				kof_swap2(p1_2nd, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A7F3) == 1 && cpunum_read_byte(0, 0x10A819) == 2)  
				kof_swap2(p1_2nd, p2_3rd);
			else if(cpunum_read_byte(0, 0x10A7F3) == 1 && cpunum_read_byte(0, 0x10A819) == 3)  
				kof_swap2(p1_2nd, p2_4th);
			else if(cpunum_read_byte(0, 0x10A7F3) == 2 && cpunum_read_byte(0, 0x10A819) == 0)  
				kof_swap2(p1_3rd, p2_1st);
			else if(cpunum_read_byte(0, 0x10A7F3) == 2 && cpunum_read_byte(0, 0x10A819) == 1)  
				kof_swap2(p1_3rd, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A7F3) == 2 && cpunum_read_byte(0, 0x10A819) == 2)  
				kof_swap2(p1_3rd, p2_3rd);
			else if(cpunum_read_byte(0, 0x10A7F3) == 2 && cpunum_read_byte(0, 0x10A819) == 3)  
				kof_swap2(p1_3rd, p2_4th);
			else if(cpunum_read_byte(0, 0x10A7F3) == 3 && cpunum_read_byte(0, 0x10A819) == 0)  
				kof_swap2(p1_4th, p2_1st);
			else if(cpunum_read_byte(0, 0x10A7F3) == 3 && cpunum_read_byte(0, 0x10A819) == 1)  
				kof_swap2(p1_4th, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A7F3) == 3 && cpunum_read_byte(0, 0x10A819) == 2)  
				kof_swap2(p1_4th, p2_3rd);
			else if(cpunum_read_byte(0, 0x10A7F3) == 3 && cpunum_read_byte(0, 0x10A819) == 3)  
				kof_swap2(p1_4th, p2_4th);
		}
	}
	break;
}
case kof2002_6p:
{
	//	int energy1 = cpunum_read_byte(0, 0x108239) | 0x0F;
	//	int energy2 = cpunum_read_byte(0, 0x108439) | 0x0F;
    if( (cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF && cpunum_read_byte(0, 0x10A7E8) == 0xFF) ||
        (cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF && cpunum_read_byte(0, 0x10A80E) == 0xFF) )
		init = 0;
    if(init == 0)
	{
		if(kPlayers == 4 || kPlayers == 2)
		{
			if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF))
				change_position(1,0,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF))
				change_position(1,0,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF))
				change_position(1,0,2,3,4,5);
		}
		else if(kPlayers == 5)
		{
			if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF))
				change_position(1,2,0,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF))
				change_position(1,2,0,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF))
				change_position(0,1,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF))
				change_position(1,0,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF))
				change_position(1,2,0,4,3,5);
		}
		else if(kPlayers == 3 || kPlayers >= 6)
		{
			if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) == 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF))
				change_position(1,2,0,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF))
				change_position(0,1,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF))
				change_position(1,0,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) == 0xFF))
				change_position(1,2,0,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7E6) == 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF))
				change_position(0,1,2,4,5,3);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF))
				change_position(1,0,2,4,5,3);
			else if((cpunum_read_byte(0, 0x10A7E6) != 0xFF && cpunum_read_byte(0, 0x10A7E7) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80C) != 0xFF && cpunum_read_byte(0, 0x10A80D) != 0xFF))
				change_position(1,2,0,4,5,3);
		}
		
		if( cpunum_read_byte(0, 0x10A7D2) == 0x60 && cpunum_read_byte(0, 0x10A7D3) == 0x32 ) 
		{
			init = 1;
		}
	}
	else
	{
		p1_1st = cpunum_read_byte(0, 0x10A7FC);
		p1_2nd = cpunum_read_byte(0, 0x10A7FD);
		p1_3rd = cpunum_read_byte(0, 0x10A7FE);
		p2_1st = cpunum_read_byte(0, 0x10A822);
		p2_2nd = cpunum_read_byte(0, 0x10A823);
		p2_3rd = cpunum_read_byte(0, 0x10A824);
		
		if( cpunum_read_byte(0, 0x10A7D2) == 0x60 && cpunum_read_byte(0, 0x10A7D3) == 0x32 )
		{
			if(cpunum_read_byte(0, 0x10A7F3) == 0 && cpunum_read_byte(0, 0x10A819) == 0)
				kof_swap(p1_1st, p2_1st);
			else if(cpunum_read_byte(0, 0x10A7F3) == 0 && cpunum_read_byte(0, 0x10A819) == 1)
				kof_swap(p1_1st, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A7F3) == 0 && cpunum_read_byte(0, 0x10A819) == 2)  
				kof_swap(p1_1st, p2_3rd);
			else if(cpunum_read_byte(0, 0x10A7F3) == 1 && cpunum_read_byte(0, 0x10A819) == 0)  
				kof_swap(p1_2nd, p2_1st);
			else if(cpunum_read_byte(0, 0x10A7F3) == 1 && cpunum_read_byte(0, 0x10A819) == 1)  
				kof_swap(p1_2nd, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A7F3) == 1 && cpunum_read_byte(0, 0x10A819) == 2)  
				kof_swap(p1_2nd, p2_3rd);
			else if(cpunum_read_byte(0, 0x10A7F3) == 2 && cpunum_read_byte(0, 0x10A819) == 0)  
				kof_swap(p1_3rd, p2_1st);
			else if(cpunum_read_byte(0, 0x10A7F3) == 2 && cpunum_read_byte(0, 0x10A819) == 1)  
				kof_swap(p1_3rd, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A7F3) == 2 && cpunum_read_byte(0, 0x10A819) == 2)  
				kof_swap(p1_3rd, p2_3rd);
		}
	}
	break;
}
case kof98_6p:
{
	int energy1 = cpunum_read_byte(0, 0x108239) | 0x0F;
	int energy2 = cpunum_read_byte(0, 0x108439) | 0x0F;
    if( (cpunum_read_byte(0, 0x10A84D) == 0 && cpunum_read_byte(0, 0x10A84E) == 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF && cpunum_read_byte(0, 0x10A850) == 0xFF) ||
        (cpunum_read_byte(0, 0x10A85E) == 0 && cpunum_read_byte(0, 0x10A85F) == 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF && cpunum_read_byte(0, 0x10A861) == 0xFF) ||
        (cpunum_read_byte(0, 0x10A84D) == 0 && energy1 == 0xFF) ||
		(cpunum_read_byte(0, 0x10A85E) == 0 && energy2 == 0xFF) )
		init = 0;

    if(init == 0)
	{
		if(kPlayers == 4 || kPlayers == 2)
		{
			if((cpunum_read_byte(0, 0x10A84E) == 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) == 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) == 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) == 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF))
				change_position(1,0,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A84E) == 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF))
				change_position(1,0,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A84E) == 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) != 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) != 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) != 0xFF))
				change_position(1,0,2,3,4,5);
		}
		else if(kPlayers == 5)
		{
			if((cpunum_read_byte(0, 0x10A84E) == 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) == 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) == 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) == 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF))
				change_position(1,2,0,3,4,5);
			else if((cpunum_read_byte(0, 0x10A84E) == 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF))
				change_position(1,2,0,3,4,5);
			else if((cpunum_read_byte(0, 0x10A84E) == 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) != 0xFF))
				change_position(0,1,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) != 0xFF))
				change_position(1,0,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) != 0xFF))
				change_position(1,2,0,4,3,5);
		}
		else if(kPlayers == 3 || kPlayers >= 6)
		{
			if((cpunum_read_byte(0, 0x10A84E) == 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) == 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) == 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) == 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF))
				change_position(1,2,0,3,4,5);
			else if((cpunum_read_byte(0, 0x10A84E) == 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF))
				change_position(0,1,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF))
				change_position(1,0,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) == 0xFF))
				change_position(1,2,0,4,3,5);
			else if((cpunum_read_byte(0, 0x10A84E) == 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) != 0xFF))
				change_position(0,1,2,4,5,3);
			else if((cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) != 0xFF))
				change_position(1,0,2,4,5,3);
			else if((cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) != 0xFF))
				change_position(1,2,0,4,5,3);
		}
		
		if( cpunum_read_byte(0, 0x10A83A) == 0x60 &&
			cpunum_read_byte(0, 0x10A84E) != 0xFF && cpunum_read_byte(0, 0x10A84F) != 0xFF && cpunum_read_byte(0, 0x10A850) != 0xFF &&
            cpunum_read_byte(0, 0x10A85F) != 0xFF && cpunum_read_byte(0, 0x10A860) != 0xFF && cpunum_read_byte(0, 0x10A861) != 0xFF )
		{
			init = 1;
		}
	}
	else
	{
		p1_1st = cpunum_read_byte(0, 0x10A854);
		p1_2nd = cpunum_read_byte(0, 0x10A855);
		p1_3rd = cpunum_read_byte(0, 0x10A856);
		p2_1st = cpunum_read_byte(0, 0x10A865);
		p2_2nd = cpunum_read_byte(0, 0x10A866);
		p2_3rd = cpunum_read_byte(0, 0x10A867);
		
		if( cpunum_read_byte(0, 0x10A83A) == 0x60 )
		{
			if(cpunum_read_byte(0, 0x10A84D) == 0 && cpunum_read_byte(0, 0x10A85E) == 0)
				kof_swap(p1_1st, p2_1st);
			else if(cpunum_read_byte(0, 0x10A84D) == 0 && cpunum_read_byte(0, 0x10A85E) == 1)
				kof_swap(p1_1st, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A84D) == 0 && cpunum_read_byte(0, 0x10A85E) == 2)  
				kof_swap(p1_1st, p2_3rd);
			else if(cpunum_read_byte(0, 0x10A84D) == 1 && cpunum_read_byte(0, 0x10A85E) == 0)  
				kof_swap(p1_2nd, p2_1st);
			else if(cpunum_read_byte(0, 0x10A84D) == 1 && cpunum_read_byte(0, 0x10A85E) == 1)  
				kof_swap(p1_2nd, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A84D) == 1 && cpunum_read_byte(0, 0x10A85E) == 2)  
				kof_swap(p1_2nd, p2_3rd);
			else if(cpunum_read_byte(0, 0x10A84D) == 2 && cpunum_read_byte(0, 0x10A85E) == 0)  
				kof_swap(p1_3rd, p2_1st);
			else if(cpunum_read_byte(0, 0x10A84D) == 2 && cpunum_read_byte(0, 0x10A85E) == 1)  
				kof_swap(p1_3rd, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A84D) == 2 && cpunum_read_byte(0, 0x10A85E) == 2)  
				kof_swap(p1_3rd, p2_3rd);
		}
	}
	break;
}
case mvsc4p:
{
    if( cpunum_read_byte(0, 0xFF5C2B) == 1 )
		init = 0;
	if(init == 0)
	{
		if(kPlayers == 2 || kPlayers >= 4)
		{
			if(cpunum_read_byte(0, 0xFF5E4C) == 0 && cpunum_read_byte(0, 0xFF5DDC) == 0)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5E4C) == 0 && cpunum_read_byte(0, 0xFF5DDC) == 1)
				change_position(0,1,3,2,4,5);
			else if(cpunum_read_byte(0, 0xFF5E4C) == 0 && cpunum_read_byte(0, 0xFF5DDC) == 2)
				change_position(0,1,3,2,4,5);
			else if(cpunum_read_byte(0, 0xFF5E4C) == 1 && cpunum_read_byte(0, 0xFF5DDC) == 0)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5E4C) == 1 && cpunum_read_byte(0, 0xFF5DDC) == 1)
				change_position(1,0,3,2,4,5);
			else if(cpunum_read_byte(0, 0xFF5E4C) == 1 && cpunum_read_byte(0, 0xFF5DDC) == 2)
				change_position(1,0,3,2,4,5);
			else if(cpunum_read_byte(0, 0xFF5E4C) == 2 && cpunum_read_byte(0, 0xFF5DDC) == 0)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5E4C) == 2 && cpunum_read_byte(0, 0xFF5DDC) == 1)
				change_position(1,0,3,2,4,5);
			else if(cpunum_read_byte(0, 0xFF5E4C) == 2 && cpunum_read_byte(0, 0xFF5DDC) == 2)
				change_position(1,0,3,2,4,5);
		}
		else if(kPlayers == 3)
		{
			if(cpunum_read_byte(0, 0xFF5E4C) == 0 && cpunum_read_byte(0, 0xFF5DDC) == 0)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5E4C) == 0 && cpunum_read_byte(0, 0xFF5DDC) == 1)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5E4C) == 0 && cpunum_read_byte(0, 0xFF5DDC) == 2)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5E4C) == 1 && cpunum_read_byte(0, 0xFF5DDC) == 0)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5E4C) == 1 && cpunum_read_byte(0, 0xFF5DDC) == 1)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5E4C) == 1 && cpunum_read_byte(0, 0xFF5DDC) == 2)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5E4C) == 2 && cpunum_read_byte(0, 0xFF5DDC) == 0)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5E4C) == 2 && cpunum_read_byte(0, 0xFF5DDC) == 1)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5E4C) == 2 && cpunum_read_byte(0, 0xFF5DDC) == 2)
				change_position(1,0,2,3,4,5);
		}
		
		if( cpunum_read_byte(0, 0xFF5C2B) == 0 )
		{
			init = 1;
            change_position(0,1,2,3,4,5);
		}
	}
	else
	{
		if(kPlayers == 1) {}
		else if(kPlayers == 2 || kPlayers == 3)
		{
			if( cpunum_read_byte(0, 0xFF3A81) == 1 )
				change_position(0,1,2,3,4,5);
			else if( cpunum_read_byte(0, 0xFF3A81) == 0 )
				change_position(1,0,2,3,4,5);
		}
		else if(kPlayers >= 4)
		{
			if( cpunum_read_byte(0, 0xFF3A81) == 1 && cpunum_read_byte(0, 0xFF3E81) == 1 )
				change_position(0,1,2,3,4,5);
			else if( cpunum_read_byte(0, 0xFF3A81) == 0 && cpunum_read_byte(0, 0xFF3E81) == 1 )
				change_position(1,0,2,3,4,5);
			else if( cpunum_read_byte(0, 0xFF3A81) == 1 && cpunum_read_byte(0, 0xFF3E81) == 0 )
				change_position(0,1,3,2,4,5);
			else if( cpunum_read_byte(0, 0xFF3A81) == 0 && cpunum_read_byte(0, 0xFF3E81) == 0 )
				change_position(1,0,3,2,4,5);
		}
	}
	break;
}
case mshvsf4p:
{
    if( cpunum_read_byte(0, 0xFF2492) == 1 )
		init = 0;
	if(init == 0)
	{
		if(kPlayers == 2 || kPlayers >= 4)
		{
			if(cpunum_read_byte(0, 0xFF4983) == 0 && cpunum_read_byte(0, 0xFF49A3) == 0)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF4983) == 0 && cpunum_read_byte(0, 0xFF49A3) == 1)
				change_position(0,1,3,2,4,5);
			else if(cpunum_read_byte(0, 0xFF4983) == 0 && cpunum_read_byte(0, 0xFF49A3) == 2)
				change_position(0,1,3,2,4,5);
			else if(cpunum_read_byte(0, 0xFF4983) == 1 && cpunum_read_byte(0, 0xFF49A3) == 0)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF4983) == 1 && cpunum_read_byte(0, 0xFF49A3) == 1)
				change_position(1,0,3,2,4,5);
			else if(cpunum_read_byte(0, 0xFF4983) == 1 && cpunum_read_byte(0, 0xFF49A3) == 2)
				change_position(1,0,3,2,4,5);
			else if(cpunum_read_byte(0, 0xFF4983) == 2 && cpunum_read_byte(0, 0xFF49A3) == 0)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF4983) == 2 && cpunum_read_byte(0, 0xFF49A3) == 1)
				change_position(1,0,3,2,4,5);
			else if(cpunum_read_byte(0, 0xFF4983) == 2 && cpunum_read_byte(0, 0xFF49A3) == 2)
				change_position(1,0,3,2,4,5);
		}
		else if(kPlayers == 3)
		{
			if(cpunum_read_byte(0, 0xFF4983) == 0 && cpunum_read_byte(0, 0xFF49A3) == 0)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF4983) == 0 && cpunum_read_byte(0, 0xFF49A3) == 1)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF4983) == 0 && cpunum_read_byte(0, 0xFF49A3) == 2)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF4983) == 1 && cpunum_read_byte(0, 0xFF49A3) == 0)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF4983) == 1 && cpunum_read_byte(0, 0xFF49A3) == 1)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF4983) == 1 && cpunum_read_byte(0, 0xFF49A3) == 2)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF4983) == 2 && cpunum_read_byte(0, 0xFF49A3) == 0)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF4983) == 2 && cpunum_read_byte(0, 0xFF49A3) == 1)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF4983) == 2 && cpunum_read_byte(0, 0xFF49A3) == 2)
				change_position(1,0,2,3,4,5);
		}
		
		if( cpunum_read_byte(0, 0xFF2492) == 0 )
		{
			init = 1;
            change_position(0,1,2,3,4,5);
		}
	}
	else
	{
		if(kPlayers == 1) {}
		else if(kPlayers == 2 || kPlayers == 3)
		{
			if( cpunum_read_byte(0, 0xFF3A61) == 0 )
				change_position(0,1,2,3,4,5);
			else if( cpunum_read_byte(0, 0xFF3A61) == 1 )
				change_position(1,0,2,3,4,5);
		}
		else if(kPlayers >= 4)
		{
			if( cpunum_read_byte(0, 0xFF3A61) == 0 && cpunum_read_byte(0, 0xFF3E61) == 0 )
				change_position(0,1,2,3,4,5);
			else if( cpunum_read_byte(0, 0xFF3A61) == 1 && cpunum_read_byte(0, 0xFF3E61) == 0 )
				change_position(1,0,2,3,4,5);
			else if( cpunum_read_byte(0, 0xFF3A61) == 0 && cpunum_read_byte(0, 0xFF3E61) == 1 )
				change_position(0,1,3,2,4,5);
			else if( cpunum_read_byte(0, 0xFF3A61) == 1 && cpunum_read_byte(0, 0xFF3E61) == 1 )
				change_position(1,0,3,2,4,5);
		}
	}
	break;
}
case xmvsf4p:
{
	if( (cpunum_read_byte(0, 0xFF4211) == 0 && cpunum_read_byte(0, 0xFF4213) == 0 && cpunum_read_byte(0, 0xFF4214) == 0) ||
		(cpunum_read_byte(0, 0xFF4611) == 0 && cpunum_read_byte(0, 0xFF4613) == 0 && cpunum_read_byte(0, 0xFF4614) == 0) )
		init = 0;
	if(init == 0)
	{
		if(kPlayers == 2 || kPlayers >= 4)
		{
			if(cpunum_read_byte(0, 0xFF5183) == 0 && cpunum_read_byte(0, 0xFF51A3) == 0)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5183) == 0 && cpunum_read_byte(0, 0xFF51A3) == 1)
				change_position(0,1,3,2,4,5);
			else if(cpunum_read_byte(0, 0xFF5183) == 0 && cpunum_read_byte(0, 0xFF51A3) == 2)
				change_position(0,1,3,2,4,5);
			else if(cpunum_read_byte(0, 0xFF5183) == 1 && cpunum_read_byte(0, 0xFF51A3) == 0)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5183) == 1 && cpunum_read_byte(0, 0xFF51A3) == 1)
				change_position(1,0,3,2,4,5);
			else if(cpunum_read_byte(0, 0xFF5183) == 1 && cpunum_read_byte(0, 0xFF51A3) == 2)
				change_position(1,0,3,2,4,5);
			else if(cpunum_read_byte(0, 0xFF5183) == 2 && cpunum_read_byte(0, 0xFF51A3) == 0)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5183) == 2 && cpunum_read_byte(0, 0xFF51A3) == 1)
				change_position(1,0,3,2,4,5);
			else if(cpunum_read_byte(0, 0xFF5183) == 2 && cpunum_read_byte(0, 0xFF51A3) == 2)
				change_position(1,0,3,2,4,5);
		}
		else if(kPlayers == 3)
		{
			if(cpunum_read_byte(0, 0xFF5183) == 0 && cpunum_read_byte(0, 0xFF51A3) == 0)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5183) == 0 && cpunum_read_byte(0, 0xFF51A3) == 1)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5183) == 0 && cpunum_read_byte(0, 0xFF51A3) == 2)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5183) == 1 && cpunum_read_byte(0, 0xFF51A3) == 0)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5183) == 1 && cpunum_read_byte(0, 0xFF51A3) == 1)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5183) == 1 && cpunum_read_byte(0, 0xFF51A3) == 2)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5183) == 2 && cpunum_read_byte(0, 0xFF51A3) == 0)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5183) == 2 && cpunum_read_byte(0, 0xFF51A3) == 1)
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0xFF5183) == 2 && cpunum_read_byte(0, 0xFF51A3) == 2)
				change_position(1,0,2,3,4,5);
		}
		
		player1_c = cpunum_read_byte(0, 0xFF4053);
		player2_c = cpunum_read_byte(0, 0xFF4853);
		player3_c = cpunum_read_byte(0, 0xFF4453);
		player4_c = cpunum_read_byte(0, 0xFF4C53);
		if( cpunum_read_byte(0, 0xFF4211) != 0 &&
            cpunum_read_byte(0, 0xFF4611) != 0 )
		{
			init = 1;
			change_position(0,1,2,3,4,5);
		}
	}
	else
	{
		if(kPlayers == 1) {}
		else if(kPlayers == 2 || kPlayers == 3)
		{
			if( cpunum_read_byte(0, 0xFF4053) == player1_c )
				change_position(0,1,2,3,4,5);
			else if( cpunum_read_byte(0, 0xFF4053) == player2_c )
				change_position(1,0,2,3,4,5);
		}
		else if(kPlayers >= 4)
		{
			if( cpunum_read_byte(0, 0xFF4053) == player1_c &&
				cpunum_read_byte(0, 0xFF4453) == player3_c )
				change_position(0,1,2,3,4,5);
			else if( cpunum_read_byte(0, 0xFF4053) == player2_c &&
				cpunum_read_byte(0, 0xFF4453) == player3_c )
				change_position(1,0,2,3,4,5);
			else if( cpunum_read_byte(0, 0xFF4053) == player1_c &&
				cpunum_read_byte(0, 0xFF4453) == player4_c )
				change_position(0,1,3,2,4,5);
			else if( cpunum_read_byte(0, 0xFF4053) == player2_c &&
				cpunum_read_byte(0, 0xFF4453) == player4_c )
				change_position(1,0,3,2,4,5);
		}
	}
	break;
}
case kof99_6p:
{
	int energy1 = cpunum_read_byte(0, 0x108239) | 0x0F;
	int energy2 = cpunum_read_byte(0, 0x108439) | 0x0F;
    if( (cpunum_read_byte(0, 0x10A7F9) == 0 && cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF && cpunum_read_byte(0, 0x10A7FC) == 0xFF) ||
        (cpunum_read_byte(0, 0x10A80E) == 0 && cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF && cpunum_read_byte(0, 0x10A811) == 0xFF) ||
        (cpunum_read_byte(0, 0x10A7F9) == 0 && energy1 == 0xFF) ||
		(cpunum_read_byte(0, 0x10A80E) == 0 && energy2 == 0xFF) ||
		cpunum_read_byte(0, 0x10A805) == 0xFF ||
		cpunum_read_byte(0, 0x10A81A) == 0xFF )
		init = 0;
    if(init == 0)
	{
        if(kPlayers == 4 || kPlayers == 2)
		{
			if((cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,0,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,0,3,2,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF))
				change_position(1,0,2,3,4,5);
		}
		else if(kPlayers == 5)
		{
			if((cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,2,0,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,2,0,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF))
				change_position(0,1,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF))
				change_position(1,0,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF))
				change_position(1,2,0,4,3,5);
		}
		else if(kPlayers == 3 || kPlayers >= 6)
		{
			if((cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) == 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,2,0,3,4,5);
			else if((cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(0,1,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,0,2,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) == 0xFF))
				change_position(1,2,0,4,3,5);
			else if((cpunum_read_byte(0, 0x10A7FA) == 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF))
				change_position(0,1,2,4,5,3);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) == 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF))
				change_position(1,0,2,4,5,3);
			else if((cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF) &&
				(cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF))
				change_position(1,2,0,4,5,3);
		}
		
		if( cpunum_read_byte(0, 0x10A7E6) == 0x60 &&
            cpunum_read_byte(0, 0x10A7FA) != 0xFF && cpunum_read_byte(0, 0x10A7FB) != 0xFF && cpunum_read_byte(0, 0x10A7FC) != 0xFF && cpunum_read_byte(0, 0x10A7FD) != 0xFF &&
            cpunum_read_byte(0, 0x10A80F) != 0xFF && cpunum_read_byte(0, 0x10A810) != 0xFF && cpunum_read_byte(0, 0x10A811) != 0xFF && cpunum_read_byte(0, 0x10A812) != 0xFF &&
			cpunum_read_byte(0, 0x10A805) != 0xFF && cpunum_read_byte(0, 0x10A81A) != 0xFF )
		{
			init = 1;
		}
	}
	else
	{
		p1_1st = cpunum_read_byte(0, 0x10A802);
		p1_2nd = cpunum_read_byte(0, 0x10A803);
		p1_3rd = cpunum_read_byte(0, 0x10A804);
		p2_1st = cpunum_read_byte(0, 0x10A817);
		p2_2nd = cpunum_read_byte(0, 0x10A818);
		p2_3rd = cpunum_read_byte(0, 0x10A819);
		
		if( cpunum_read_byte(0, 0x10A7E6) == 0x60 )
		{
			if(cpunum_read_byte(0, 0x10A7F9) == 0 && cpunum_read_byte(0, 0x10A80E) == 0)
				kof_swap(p1_1st, p2_1st);
			else if(cpunum_read_byte(0, 0x10A7F9) == 0 && cpunum_read_byte(0, 0x10A80E) == 1)
				kof_swap(p1_1st, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A7F9) == 0 && cpunum_read_byte(0, 0x10A80E) == 2)  
				kof_swap(p1_1st, p2_3rd);
			else if(cpunum_read_byte(0, 0x10A7F9) == 1 && cpunum_read_byte(0, 0x10A80E) == 0)  
				kof_swap(p1_2nd, p2_1st);
			else if(cpunum_read_byte(0, 0x10A7F9) == 1 && cpunum_read_byte(0, 0x10A80E) == 1)  
				kof_swap(p1_2nd, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A7F9) == 1 && cpunum_read_byte(0, 0x10A80E) == 2)  
				kof_swap(p1_2nd, p2_3rd);
			else if(cpunum_read_byte(0, 0x10A7F9) == 2 && cpunum_read_byte(0, 0x10A80E) == 0)  
				kof_swap(p1_3rd, p2_1st);
			else if(cpunum_read_byte(0, 0x10A7F9) == 2 && cpunum_read_byte(0, 0x10A80E) == 1)  
				kof_swap(p1_3rd, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A7F9) == 2 && cpunum_read_byte(0, 0x10A80E) == 2)  
				kof_swap(p1_3rd, p2_3rd);
		}
	}
	break;
}
case kof97_6p:
{
	int energy1 = cpunum_read_byte(0, 0x108239) | 0x0F;
	int energy2 = cpunum_read_byte(0, 0x108439) | 0x0F;
	
    if( (cpunum_read_byte(0, 0x10A84A) == 0 && cpunum_read_byte(0, 0x108239) == 0 && cpunum_read_byte(0, 0x10A851) == 0 && cpunum_read_byte(0, 0x10A852) == 0 && cpunum_read_byte(0, 0x10A853) == 0) ||
		(cpunum_read_byte(0, 0x10A84A) == 0 && energy1 == 0xFF ) ||
		(cpunum_read_byte(0, 0x10A85B) == 0 && cpunum_read_byte(0, 0x108439) == 0 && cpunum_read_byte(0, 0x10A862) == 0 && cpunum_read_byte(0, 0x10A863) == 0 && cpunum_read_byte(0, 0x10A864) == 0) ||
		(cpunum_read_byte(0, 0x10A85B) == 0 && energy2 == 0xFF ) )
        init = 0;
	if(init == 0)
	{
		if(kPlayers == 4 || kPlayers == 2)
		{
			if(cpunum_read_byte(0, 0x10A84A) == 0 && cpunum_read_byte(0, 0x10A85B) == 0)
				change_position(0,1,3,2,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 0 && cpunum_read_byte(0, 0x10A85B) == 1)
				change_position(0,1,3,2,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 0 && cpunum_read_byte(0, 0x10A85B) == 2)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 0 && cpunum_read_byte(0, 0x10A85B) == 3)  
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 1 && cpunum_read_byte(0, 0x10A85B) == 0)  
				change_position(0,1,3,2,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 1 && cpunum_read_byte(0, 0x10A85B) == 1)  
				change_position(0,1,3,2,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 1 && cpunum_read_byte(0, 0x10A85B) == 2)  
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 1 && cpunum_read_byte(0, 0x10A85B) == 3)  
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 2 && cpunum_read_byte(0, 0x10A85B) == 0)  
				change_position(1,0,3,2,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 2 && cpunum_read_byte(0, 0x10A85B) == 1)  
				change_position(1,0,3,2,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 2 && cpunum_read_byte(0, 0x10A85B) == 2)  
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 2 && cpunum_read_byte(0, 0x10A85B) == 3)  
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 3 && cpunum_read_byte(0, 0x10A85B) == 0)  
				change_position(1,0,3,2,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 3 && cpunum_read_byte(0, 0x10A85B) == 1)  
				change_position(1,0,3,2,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 3 && cpunum_read_byte(0, 0x10A85B) == 2)  
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 3 && cpunum_read_byte(0, 0x10A85B) == 3)  
				change_position(1,0,2,3,4,5);
		}
		else if(kPlayers == 5)
		{
			if(cpunum_read_byte(0, 0x10A84A) == 0 && cpunum_read_byte(0, 0x10A85B) == 0)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 0 && cpunum_read_byte(0, 0x10A85B) == 1)
				change_position(0,1,2,4,3,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 0 && cpunum_read_byte(0, 0x10A85B) == 2)
				change_position(0,1,2,4,5,3);
			else if(cpunum_read_byte(0, 0x10A84A) == 0 && cpunum_read_byte(0, 0x10A85B) == 3)  
				change_position(0,1,2,4,5,3);
			else if(cpunum_read_byte(0, 0x10A84A) == 1 && cpunum_read_byte(0, 0x10A85B) == 0)  
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 1 && cpunum_read_byte(0, 0x10A85B) == 1)  
				change_position(1,0,2,4,3,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 1 && cpunum_read_byte(0, 0x10A85B) == 2)  
				change_position(1,0,2,4,5,3);
			else if(cpunum_read_byte(0, 0x10A84A) == 1 && cpunum_read_byte(0, 0x10A85B) == 3)  
				change_position(1,0,2,4,5,3);
			else if(cpunum_read_byte(0, 0x10A84A) == 2 && cpunum_read_byte(0, 0x10A85B) == 0)  
				change_position(1,2,0,3,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 2 && cpunum_read_byte(0, 0x10A85B) == 1)  
				change_position(1,2,0,4,3,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 2 && cpunum_read_byte(0, 0x10A85B) == 2)  
				change_position(1,2,0,4,5,3);
			else if(cpunum_read_byte(0, 0x10A84A) == 2 && cpunum_read_byte(0, 0x10A85B) == 3)  
				change_position(1,2,0,4,5,3);
			else if(cpunum_read_byte(0, 0x10A84A) == 3 && cpunum_read_byte(0, 0x10A85B) == 0)  
				change_position(1,2,0,3,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 3 && cpunum_read_byte(0, 0x10A85B) == 1)  
				change_position(1,2,0,4,3,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 3 && cpunum_read_byte(0, 0x10A85B) == 2)  
				change_position(1,2,0,4,5,3);
			else if(cpunum_read_byte(0, 0x10A84A) == 3 && cpunum_read_byte(0, 0x10A85B) == 3)  
				change_position(1,2,0,4,5,3);
		}
		else if(kPlayers == 3 || kPlayers >= 6)
		{
			if(cpunum_read_byte(0, 0x10A84A) == 0 && cpunum_read_byte(0, 0x10A85B) == 0)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 0 && cpunum_read_byte(0, 0x10A85B) == 1)
				change_position(0,1,2,4,3,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 0 && cpunum_read_byte(0, 0x10A85B) == 2)
				change_position(0,1,2,4,5,3);
			else if(cpunum_read_byte(0, 0x10A84A) == 0 && cpunum_read_byte(0, 0x10A85B) == 3)  
				change_position(0,1,2,4,5,3);
			else if(cpunum_read_byte(0, 0x10A84A) == 1 && cpunum_read_byte(0, 0x10A85B) == 0)  
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 1 && cpunum_read_byte(0, 0x10A85B) == 1)  
				change_position(1,0,2,4,3,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 1 && cpunum_read_byte(0, 0x10A85B) == 2)  
				change_position(1,0,2,4,5,3);
			else if(cpunum_read_byte(0, 0x10A84A) == 1 && cpunum_read_byte(0, 0x10A85B) == 3)  
				change_position(1,0,2,4,5,3);
			else if(cpunum_read_byte(0, 0x10A84A) == 2 && cpunum_read_byte(0, 0x10A85B) == 0)  
				change_position(1,2,0,3,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 2 && cpunum_read_byte(0, 0x10A85B) == 1)  
				change_position(1,2,0,4,3,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 2 && cpunum_read_byte(0, 0x10A85B) == 2)  
				change_position(1,2,0,4,5,3);
			else if(cpunum_read_byte(0, 0x10A84A) == 2 && cpunum_read_byte(0, 0x10A85B) == 3)  
				change_position(1,2,0,4,5,3);
			else if(cpunum_read_byte(0, 0x10A84A) == 3 && cpunum_read_byte(0, 0x10A85B) == 0)  
				change_position(1,2,0,3,4,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 3 && cpunum_read_byte(0, 0x10A85B) == 1)  
				change_position(1,2,0,4,3,5);
			else if(cpunum_read_byte(0, 0x10A84A) == 3 && cpunum_read_byte(0, 0x10A85B) == 2)  
				change_position(1,2,0,4,5,3);
			else if(cpunum_read_byte(0, 0x10A84A) == 3 && cpunum_read_byte(0, 0x10A85B) == 3)  
				change_position(1,2,0,4,5,3);
		}
		
		if( cpunum_read_byte(0, 0x10A83A) == 0x60 )
		{
			init = 1;
		}
	}
	else
	{
		p1_1st = cpunum_read_byte(0, 0x10A851);
		p1_2nd = cpunum_read_byte(0, 0x10A852);
		p1_3rd = cpunum_read_byte(0, 0x10A853);
		p2_1st = cpunum_read_byte(0, 0x10A862);
		p2_2nd = cpunum_read_byte(0, 0x10A863);
		p2_3rd = cpunum_read_byte(0, 0x10A864);
		
		if( cpunum_read_byte(0, 0x10A83A) == 0x60 )
		{
			if(cpunum_read_byte(0, 0x10A84A) == 0 && cpunum_read_byte(0, 0x10A85B) == 0)
				kof_swap(p1_1st, p2_1st);
			else if(cpunum_read_byte(0, 0x10A84A) == 0 && cpunum_read_byte(0, 0x10A85B) == 1)
				kof_swap(p1_1st, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A84A) == 0 && cpunum_read_byte(0, 0x10A85B) == 2)  
				kof_swap(p1_1st, p2_3rd);
			else if(cpunum_read_byte(0, 0x10A84A) == 1 && cpunum_read_byte(0, 0x10A85B) == 0)  
				kof_swap(p1_2nd, p2_1st);
			else if(cpunum_read_byte(0, 0x10A84A) == 1 && cpunum_read_byte(0, 0x10A85B) == 1)  
				kof_swap(p1_2nd, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A84A) == 1 && cpunum_read_byte(0, 0x10A85B) == 2)  
				kof_swap(p1_2nd, p2_3rd);
			else if(cpunum_read_byte(0, 0x10A84A) == 2 && cpunum_read_byte(0, 0x10A85B) == 0)  
				kof_swap(p1_3rd, p2_1st);
			else if(cpunum_read_byte(0, 0x10A84A) == 2 && cpunum_read_byte(0, 0x10A85B) == 1)  
				kof_swap(p1_3rd, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A84A) == 2 && cpunum_read_byte(0, 0x10A85B) == 2)  
				kof_swap(p1_3rd, p2_3rd);
		}
	}
	break;
}
case kof96_6p:
{
	int energy1 = cpunum_read_byte(0, 0x108239) | 0x0F;
	int energy2 = cpunum_read_byte(0, 0x108439) | 0x0F;
	
    if( (cpunum_read_byte(0, 0x10A845) == 0 && cpunum_read_byte(0, 0x108239) == 0 && cpunum_read_byte(0, 0x10A84c) == 0 && cpunum_read_byte(0, 0x10A84d) == 0 && cpunum_read_byte(0, 0x10A84e) == 0) ||
		(cpunum_read_byte(0, 0x10A845) == 0 && energy1 == 0xFF ) ||
		(cpunum_read_byte(0, 0x10A856) == 0 && cpunum_read_byte(0, 0x108439) == 0 && cpunum_read_byte(0, 0x10A85d) == 0 && cpunum_read_byte(0, 0x10A85e) == 0 && cpunum_read_byte(0, 0x10A85f) == 0) ||
		(cpunum_read_byte(0, 0x10A856) == 0 && energy2 == 0xFF ) )
        init = 0;
	if(init == 0)
	{
		if(kPlayers == 4 || kPlayers == 2)
		{
			if(cpunum_read_byte(0, 0x10A845) == 0 && cpunum_read_byte(0, 0x10A856) == 0)
				change_position(0,1,3,2,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 0 && cpunum_read_byte(0, 0x10A856) == 1)
				change_position(0,1,3,2,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 0 && cpunum_read_byte(0, 0x10A856) == 2)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 0 && cpunum_read_byte(0, 0x10A856) == 3)  
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 1 && cpunum_read_byte(0, 0x10A856) == 0)  
				change_position(0,1,3,2,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 1 && cpunum_read_byte(0, 0x10A856) == 1)  
				change_position(0,1,3,2,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 1 && cpunum_read_byte(0, 0x10A856) == 2)  
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 1 && cpunum_read_byte(0, 0x10A856) == 3)  
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 2 && cpunum_read_byte(0, 0x10A856) == 0)  
				change_position(1,0,3,2,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 2 && cpunum_read_byte(0, 0x10A856) == 1)  
				change_position(1,0,3,2,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 2 && cpunum_read_byte(0, 0x10A856) == 2)  
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 2 && cpunum_read_byte(0, 0x10A856) == 3)  
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 3 && cpunum_read_byte(0, 0x10A856) == 0)  
				change_position(1,0,3,2,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 3 && cpunum_read_byte(0, 0x10A856) == 1)  
				change_position(1,0,3,2,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 3 && cpunum_read_byte(0, 0x10A856) == 2)  
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 3 && cpunum_read_byte(0, 0x10A856) == 3)  
				change_position(1,0,2,3,4,5);
		}
		else if(kPlayers == 5)
		{
			if(cpunum_read_byte(0, 0x10A845) == 0 && cpunum_read_byte(0, 0x10A856) == 0)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 0 && cpunum_read_byte(0, 0x10A856) == 1)
				change_position(0,1,2,4,3,5);
			else if(cpunum_read_byte(0, 0x10A845) == 0 && cpunum_read_byte(0, 0x10A856) == 2)
				change_position(0,1,2,4,5,3);
			else if(cpunum_read_byte(0, 0x10A845) == 0 && cpunum_read_byte(0, 0x10A856) == 3)  
				change_position(0,1,2,4,5,3);
			else if(cpunum_read_byte(0, 0x10A845) == 1 && cpunum_read_byte(0, 0x10A856) == 0)  
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 1 && cpunum_read_byte(0, 0x10A856) == 1)  
				change_position(1,0,2,4,3,5);
			else if(cpunum_read_byte(0, 0x10A845) == 1 && cpunum_read_byte(0, 0x10A856) == 2)  
				change_position(1,0,2,4,5,3);
			else if(cpunum_read_byte(0, 0x10A845) == 1 && cpunum_read_byte(0, 0x10A856) == 3)  
				change_position(1,0,2,4,5,3);
			else if(cpunum_read_byte(0, 0x10A845) == 2 && cpunum_read_byte(0, 0x10A856) == 0)  
				change_position(1,2,0,3,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 2 && cpunum_read_byte(0, 0x10A856) == 1)  
				change_position(1,2,0,4,3,5);
			else if(cpunum_read_byte(0, 0x10A845) == 2 && cpunum_read_byte(0, 0x10A856) == 2)  
				change_position(1,2,0,4,5,3);
			else if(cpunum_read_byte(0, 0x10A845) == 2 && cpunum_read_byte(0, 0x10A856) == 3)  
				change_position(1,2,0,4,5,3);
			else if(cpunum_read_byte(0, 0x10A845) == 3 && cpunum_read_byte(0, 0x10A856) == 0)  
				change_position(1,2,0,3,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 3 && cpunum_read_byte(0, 0x10A856) == 1)  
				change_position(1,2,0,4,3,5);
			else if(cpunum_read_byte(0, 0x10A845) == 3 && cpunum_read_byte(0, 0x10A856) == 2)  
				change_position(1,2,0,4,5,3);
			else if(cpunum_read_byte(0, 0x10A845) == 3 && cpunum_read_byte(0, 0x10A856) == 3)  
				change_position(1,2,0,4,5,3);
		}
		else if(kPlayers == 3 || kPlayers >= 6)
		{
			if(cpunum_read_byte(0, 0x10A845) == 0 && cpunum_read_byte(0, 0x10A856) == 0)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 0 && cpunum_read_byte(0, 0x10A856) == 1)
				change_position(0,1,2,4,3,5);
			else if(cpunum_read_byte(0, 0x10A845) == 0 && cpunum_read_byte(0, 0x10A856) == 2)
				change_position(0,1,2,4,5,3);
			else if(cpunum_read_byte(0, 0x10A845) == 0 && cpunum_read_byte(0, 0x10A856) == 3)  
				change_position(0,1,2,4,5,3);
			else if(cpunum_read_byte(0, 0x10A845) == 1 && cpunum_read_byte(0, 0x10A856) == 0)  
				change_position(1,0,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 1 && cpunum_read_byte(0, 0x10A856) == 1)  
				change_position(1,0,2,4,3,5);
			else if(cpunum_read_byte(0, 0x10A845) == 1 && cpunum_read_byte(0, 0x10A856) == 2)  
				change_position(1,0,2,4,5,3);
			else if(cpunum_read_byte(0, 0x10A845) == 1 && cpunum_read_byte(0, 0x10A856) == 3)  
				change_position(1,0,2,4,5,3);
			else if(cpunum_read_byte(0, 0x10A845) == 2 && cpunum_read_byte(0, 0x10A856) == 0)  
				change_position(1,2,0,3,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 2 && cpunum_read_byte(0, 0x10A856) == 1)  
				change_position(1,2,0,4,3,5);
			else if(cpunum_read_byte(0, 0x10A845) == 2 && cpunum_read_byte(0, 0x10A856) == 2)  
				change_position(1,2,0,4,5,3);
			else if(cpunum_read_byte(0, 0x10A845) == 2 && cpunum_read_byte(0, 0x10A856) == 3)  
				change_position(1,2,0,4,5,3);
			else if(cpunum_read_byte(0, 0x10A845) == 3 && cpunum_read_byte(0, 0x10A856) == 0)  
				change_position(1,2,0,3,4,5);
			else if(cpunum_read_byte(0, 0x10A845) == 3 && cpunum_read_byte(0, 0x10A856) == 1)  
				change_position(1,2,0,4,3,5);
			else if(cpunum_read_byte(0, 0x10A845) == 3 && cpunum_read_byte(0, 0x10A856) == 2)  
				change_position(1,2,0,4,5,3);
			else if(cpunum_read_byte(0, 0x10A845) == 3 && cpunum_read_byte(0, 0x10A856) == 3)  
				change_position(1,2,0,4,5,3);
		}
		
		if( cpunum_read_byte(0, 0x10A836) == 0x60 )
		{
			init = 1;
		}
	}
	else
	{
		p1_1st = cpunum_read_byte(0, 0x10A84c);
		p1_2nd = cpunum_read_byte(0, 0x10A84d);
		p1_3rd = cpunum_read_byte(0, 0x10A84e);
		p2_1st = cpunum_read_byte(0, 0x10A85d);
		p2_2nd = cpunum_read_byte(0, 0x10A85e);
		p2_3rd = cpunum_read_byte(0, 0x10A85f);
		
		if( cpunum_read_byte(0, 0x10A836) == 0x60 )
		{
			if(cpunum_read_byte(0, 0x10A845) == 0 && cpunum_read_byte(0, 0x10A856) == 0)
				kof_swap(p1_1st, p2_1st);
			else if(cpunum_read_byte(0, 0x10A845) == 0 && cpunum_read_byte(0, 0x10A856) == 1)
				kof_swap(p1_1st, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A845) == 0 && cpunum_read_byte(0, 0x10A856) == 2)  
				kof_swap(p1_1st, p2_3rd);
			else if(cpunum_read_byte(0, 0x10A845) == 1 && cpunum_read_byte(0, 0x10A856) == 0)  
				kof_swap(p1_2nd, p2_1st);
			else if(cpunum_read_byte(0, 0x10A845) == 1 && cpunum_read_byte(0, 0x10A856) == 1)  
				kof_swap(p1_2nd, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A845) == 1 && cpunum_read_byte(0, 0x10A856) == 2)  
				kof_swap(p1_2nd, p2_3rd);
			else if(cpunum_read_byte(0, 0x10A845) == 2 && cpunum_read_byte(0, 0x10A856) == 0)  
				kof_swap(p1_3rd, p2_1st);
			else if(cpunum_read_byte(0, 0x10A845) == 2 && cpunum_read_byte(0, 0x10A856) == 1)  
				kof_swap(p1_3rd, p2_2nd);
			else if(cpunum_read_byte(0, 0x10A845) == 2 && cpunum_read_byte(0, 0x10A856) == 2)  
				kof_swap(p1_3rd, p2_3rd);
		}
	}
	break;
}
case kizuna_4p:
{
	if( (cpunum_read_byte(0, 0x1088EC) == 0xFF && cpunum_read_byte(0, 0x1088EE) == 0xFF) ||
		(cpunum_read_byte(0, 0x1088ED) == 0xFF && cpunum_read_byte(0, 0x1088EF) == 0xFF) )
		init = 0;

	if(init == 0)
	{
		if(kPlayers == 2 || kPlayers >= 4)
		{
			if((cpunum_read_byte(0, 0x1088EC) == 0xFF && cpunum_read_byte(0, 0x1088ED) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x1088EC) != 0xFF && cpunum_read_byte(0, 0x1088ED) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x1088EC) == 0xFF && cpunum_read_byte(0, 0x1088ED) != 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x1088EC) != 0xFF && cpunum_read_byte(0, 0x1088ED) != 0xFF))
				change_position(1,0,3,2,4,5);
		}
		else if(kPlayers == 3)
		{
			if((cpunum_read_byte(0, 0x1088EC) == 0xFF && cpunum_read_byte(0, 0x1088ED) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x1088EC) != 0xFF && cpunum_read_byte(0, 0x1088ED) == 0xFF))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x1088EC) == 0xFF && cpunum_read_byte(0, 0x1088ED) != 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x1088EC) != 0xFF && cpunum_read_byte(0, 0x1088ED) != 0xFF))
				change_position(1,0,2,3,4,5);
		}
		
		player1_c = cpunum_read_byte(0, 0x1088EC);
		player2_c = cpunum_read_byte(0, 0x1088EE);
		player3_c = cpunum_read_byte(0, 0x1088ED);
		player4_c = cpunum_read_byte(0, 0x1088EF);
		player1_sub = -1;
		player2_sub = -1;
		player3_sub = -1;
		player4_sub = -1;
		
		if(player1_c == 0x07)
			player1_sub = 0x0B;
		else if(player1_c == 0x87)
			player1_sub = 0x8B;
		if(player2_c == 0x07)
			player2_sub = 0x0B;
		else if(player2_c == 0x87)
			player2_sub = 0x8B;
		if(player3_c == 0x07)
			player3_sub = 0x0B;
		else if(player3_c == 0x87)
			player3_sub = 0x8B;
		if(player4_c == 0x07)
			player4_sub = 0x0B;
		else if(player4_c == 0x87)
			player4_sub = 0x8B;
		
		if(cpunum_read_byte(0, 0x1088FB) == 0x10)
		{
			init= 1;
		}
	}
	else
	{
        if(kPlayers == 1) {}
        else if(kPlayers == 2 || kPlayers == 3)
        {
			if(cpunum_read_byte(0, 0x10821F) == player1_c || cpunum_read_byte(0, 0x10821F) == player1_sub)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0x10821F) == player2_c || cpunum_read_byte(0, 0x10821F) == player2_sub)
				change_position(1,0,2,3,4,5);
        }
		else if(kPlayers >= 4)
		{
			if( (cpunum_read_byte(0, 0x10821F) == player1_c || cpunum_read_byte(0, 0x10821F) == player1_sub) &&
				(cpunum_read_byte(0, 0x10841F) == player3_c || cpunum_read_byte(0, 0x10841F) == player3_sub) )
				change_position(0,1,2,3,4,5);
			else if( (cpunum_read_byte(0, 0x10821F) == player2_c || cpunum_read_byte(0, 0x10821F) == player2_sub) &&
				(cpunum_read_byte(0, 0x10841F) == player3_c || cpunum_read_byte(0, 0x10841F) == player3_sub) )
				change_position(1,0,2,3,4,5);
			else if( (cpunum_read_byte(0, 0x10821F) == player1_c || cpunum_read_byte(0, 0x10821F) == player1_sub) &&
				(cpunum_read_byte(0, 0x10841F) == player4_c || cpunum_read_byte(0, 0x10841F) == player4_sub) )
				change_position(0,1,3,2,4,5);
			else if( (cpunum_read_byte(0, 0x10821F) == player2_c || cpunum_read_byte(0, 0x10821F) == player2_sub) &&
				(cpunum_read_byte(0, 0x10841F) == player4_c || cpunum_read_byte(0, 0x10841F) == player4_sub) )
				change_position(1,0,3,2,4,5);
		}
	}
	break;
}
case rotd_4p:
{
	if( (cpunum_read_byte(0, 0x106BE2) == 0 && cpunum_read_byte(0, 0x106BE6) == 0) ||
		(cpunum_read_byte(0, 0x106BF0) == 0 && cpunum_read_byte(0, 0x106BF4) == 0) )
		init = 0;
	if(init == 0)
	{
		if(kPlayers == 2 || kPlayers >= 4)
		{
			if((cpunum_read_byte(0, 0x106BE2) == 0 && cpunum_read_byte(0, 0x106BF0) == 0))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x106BE2) == 0xFF && cpunum_read_byte(0, 0x106BF0) == 0))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x106BE2) == 0 && cpunum_read_byte(0, 0x106BF0) == 0xFF))
				change_position(0,1,3,2,4,5);
			else if((cpunum_read_byte(0, 0x106BE2) == 0xFF && cpunum_read_byte(0, 0x106BF0) == 0xFF))
				change_position(1,0,3,2,4,5);
		}
		else if(kPlayers == 3)
		{
			if((cpunum_read_byte(0, 0x106BE2) == 0 && cpunum_read_byte(0, 0x106BF0) == 0))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x106BE2) == 0xFF && cpunum_read_byte(0, 0x106BF0) == 0))
				change_position(1,0,2,3,4,5);
			else if((cpunum_read_byte(0, 0x106BE2) == 0 && cpunum_read_byte(0, 0x106BF0) == 0xFF))
				change_position(0,1,2,3,4,5);
			else if((cpunum_read_byte(0, 0x106BE2) == 0xFF && cpunum_read_byte(0, 0x106BF0) == 0xFF))
				change_position(1,0,2,3,4,5);
		}
		
		if( cpunum_read_byte(0, 0x106BE2) == 0xFF && cpunum_read_byte(0, 0x106BE6) == 0xFF &&
			cpunum_read_byte(0, 0x106BF0) == 0xFF && cpunum_read_byte(0, 0x106BF4) == 0xFF )
		{
			player1_c = cpunum_read_byte(0, 0x106BE3);
			player2_c = cpunum_read_byte(0, 0x106BE7);
			player3_c = cpunum_read_byte(0, 0x106BF1);
			player4_c = cpunum_read_byte(0, 0x106BF5);
			init = 1;
		}
	}
	else
	{
        if(kPlayers == 1) {}
        else if(kPlayers == 2 || kPlayers == 3)
        {
			if(cpunum_read_byte(0, 0x102763) == player2_c)
				change_position(0,1,2,3,4,5);
			else if(cpunum_read_byte(0, 0x102763) == player1_c)
				change_position(1,0,2,3,4,5);
        }
		else if(kPlayers >= 4)
		{
			if( (cpunum_read_byte(0, 0x102763) == player2_c) &&
				(cpunum_read_byte(0, 0x1025EB) == player4_c) )
				change_position(0,1,2,3,4,5);
			else if( (cpunum_read_byte(0, 0x102763) == player1_c) &&
				(cpunum_read_byte(0, 0x1025EB) == player4_c) )
				change_position(1,0,2,3,4,5);
			else if( (cpunum_read_byte(0, 0x102763) == player2_c) &&
				(cpunum_read_byte(0, 0x1025EB) == player3_c) )
				change_position(0,1,3,2,4,5);
			else if( (cpunum_read_byte(0, 0x102763) == player1_c) &&
				(cpunum_read_byte(0, 0x1025EB) == player3_c) )
				change_position(1,0,3,2,4,5);
		}
	}
	break;
}
case lbowling_4p:
{
	if(cpunum_read_byte(0, 0x102C0C) == 0x00 && cpunum_read_byte(0, 0x102C0D) == 0x01)
		change_position(0,1,2,3,4,5);
	else if(cpunum_read_byte(0, 0x102C0C) == 0x02 && cpunum_read_byte(0, 0x102C0D) == 0x01)
		change_position(2,1,0,3,4,5);
	else if(cpunum_read_byte(0, 0x102C0C) == 0x00 && cpunum_read_byte(0, 0x102C0D) == 0x03)
		change_position(0,3,2,1,4,5);
	else if(cpunum_read_byte(0, 0x102C0C) == 0x02 && cpunum_read_byte(0, 0x102C0D) == 0x03)
		change_position(2,3,0,1,4,5);
	break;
}
case cyberbt2p:
{ p2 = 2; p3 = 1; break; }
case loderndf_vs:
{ p2 = 2; p3 = 1; break; }
case none: break;
}
