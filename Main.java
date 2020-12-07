package tomogachi;

import java.util.Scanner;

public class Main {
	
	public int healthStat;
	public int hungerStat;
	public int energyStat;
	public int loveStat;
	
	public int time;
	public String character;

	public static void main(String[] args) {
		
		Main pet = new Main();
		Scanner scan = new Scanner(System.in);
		
		int choice;
		
		pet.chooseCharacter();
		pet.setStats();
		pet.output();
		
		while(pet.isAlive()) {
			System.out.println("What do you want to do to your pet? \n"
							 + "1. give a snack \n"
							 + "2. give a meal \n"
							 + "3. play fetch \n"
							 + "4. go on a run \n" 
							 + "5. give pets \n"
							 + "6. give a treat \n"
							 + "7. take a nap \n"
							 + "8. go to bed ");
			if(pet.healthStat <= 15) {
				System.out.println("9. scold");
			}
			choice = scan.nextInt();
			switch (choice) {
			case 1:
				pet.eatSnack();
				break;
			case 2:
				pet.eatMeal();
				break;
			case 3:
				pet.playFetch();
				break;
			case 4:
				pet.goOnRun();
				break;
			case 5:
				pet.pets();
				break;
			case 6:
				pet.eatTreat();
				break;
			case 7:
				pet.takeNap();
				break;
			case 8:
				pet.goBed();
				break;
			case 9:
				pet.scold();
				break;
			default:
				break;
			}
			
		}
		System.out.println("RIP");
		scan.close();
	}
	
	/****************************************************
	 * GAME FUNCTION                                    *
	 ****************************************************/
	
	/**
	 * label 1
	 * 
	 * sets stats to start the game
	 */
	public void setStats() {
		healthStat = 80;
		hungerStat = 80;
		energyStat = 80;
		loveStat = 80;
		time = 1200;
	}
	
	/**
	 * label 2
	 * 
	 * check to see if character is alive to continue playing game
	 * @return true if character is alive
	 */
	public boolean isAlive() {
		if(healthStat > 0 && hungerStat > 0 && energyStat > 0 && loveStat > 0) {
			return true;
		} else {
			return false;
		}
	}
	
	/**
	 * label 3
	 * 
	 * POSSIBLY FLIP TO GO TOWARDS NEGATIVE IN ASSEMBLY
	 * 
	 * calculate military time
	 * @param offset amount of time to pass
	 * @return time after action
	 */
	public int addTime(int offset) {
		time = time + offset;
		
		if(offset == 480) {
			time = time + 800;
		}
		
		if(time % 100 > 59) {
			time = time + time % 100;
		}
		
		if(time >= 2400) {
			time = time - 2400;
		}
		return time;
	}
	
	/**
	 * label 4
	 * 
	 * choose ascii art character to play with
	 */
	public void chooseCharacter() {
		Scanner scan = new Scanner(System.in);
		int choice;
		System.out.println("Which character do you want? \n"
						 + "1. Dog \n"
						 + "2. Cat \n");
		choice = scan.nextInt();
		if(choice == 1) {
			character = "  __\r\n" + 
						"o-''|\\_____/)\r\n" + 
						" \\_/|_)     )\r\n" + 
						"    \\  __  /\r\n" + 
						"    (_/ (_/    \r\n";
		} else if(choice == 2) {
			character = "  ^~^  ,\r\n" + 
						" ('Y') )\r\n" + 
						" /   \\/ \r\n" + 
						"(\\|||/)";
		}
		scan.close();
	}
	
	/**
	 * label 5
	 */
	public void output() {
		System.out.println("\n\n\n");
		System.out.println("Health: " + healthStat + "\tHunger: " + hungerStat + "\tEnergy: " + energyStat + "\tLove: " + loveStat);
		System.out.println("Time: " + time);
		System.out.println(character);	
	}
	
	/***************************************************
	 * MAIN STATS                                      *
	 ***************************************************/
	
	/**
	 * label 4
	 * 
	 * make sure no stats are above 100%
	 */
	public void confirmStats() {
		if(healthStat > 100) {
			healthStat = 100;
		}
		
		if(healthStat > 100) {
			healthStat = 100;
		}
		if(energyStat > 100) {
			healthStat = 100;
		}
		
		if(loveStat > 100) {
			healthStat = 100;
		}
		
	}
	
	
	/*************************************************
	 * ACTIONS                                       *
	 *************************************************/
	
	/**
	 * label 5
	 * 
	 * hunger + 10
	 * energy + 5
	 */
	public void eatSnack() {
		addTime(10);
		hungerStat = hungerStat + 10;
		energyStat = energyStat + 5;
	}
	
	/**
	 * label 6
	 * 
	 * hunger + 25
	 * energy + 10
	 */
	public void eatMeal() {
		addTime(30);
		hungerStat = hungerStat + 25;
		energyStat = energyStat + 10;
	}
	
	/**
	 * label 7
	 * 
	 * hunger + 5
	 * love + 10
	 * health - 10
	 */
	public void eatTreat() {
		addTime(5);
		hungerStat = hungerStat + 5;
		loveStat = loveStat + 10;
		healthStat = healthStat - 10;
	}
	
	/**
	 * label 8
	 * 
	 * energy - 15
	 * love + 10
	 * health + 5
	 */
	public void playFetch() {
		addTime(30);
		energyStat = energyStat - 15;
		loveStat = loveStat + 10;
		healthStat = healthStat + 5;
	}
	
	/**
	 * label 9
	 * 
	 * energy - 40
	 * love + 10
	 * health + 15
	 */
	public void goOnRun() {
		addTime(60);
		energyStat = energyStat - 40;
		loveStat = loveStat + 10;
		healthStat = healthStat + 15;
	}
	
	/**
	 * label 10
	 * 
	 * love + 30
	 * health + 10
	 * energy - 5
	 */
	public void pets() {
		addTime(10);
		loveStat = loveStat + 30;
		healthStat = healthStat + 10;
		energyStat = energyStat - 5;
	}
	
	/**label 11
	 * 
	 * energy + 10
	 * hunger - 5
	 */
	public void takeNap() {
		addTime(30);
		energyStat = energyStat + 10;
		hungerStat = hungerStat - 5;
	}
	
	/**
	 * label 12
	 * 
	 * energy + 40
	 * hunger - 20
	 */
	public void goBed() {
		addTime(480);
		energyStat = energyStat + 40;
		hungerStat = hungerStat - 20;
	}
	
	/**
	 * label 13
	 * 
	 * love - 15
	 */
	public void scold() {
		addTime(10);
		loveStat = loveStat - 15;
	}

}
