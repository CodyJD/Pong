#include "titles.h"

void clearScreen()
{
  cout << "\n\n\n\n\n\n\n\n\n\n";
}

void startScreen() {
  cout << "            " << "     ___         ___           ___           ___     " << endl;
  cout << "            " << "    /\\  \\       /\\  \\         /\\  \\         /\\__\\    " << endl;
  cout << "            " << "   /::\\  \\     /::\\  \\        \\:\\  \\       /:/ _/_   " << endl;
  cout << "            " << "  /:/\\:\\__\\   /:/\\:\\  \\        \\:\\  \\     /:/ /\\  \\  " << endl;
  cout << "            " << " /:/ /:/  /  /:/  \\:\\  \\   _____\\:\\  \\   /:/ /::\\  \\ " << endl;
  cout << "            " << "/:/_/:/  /  /:/__/ \\:\\__\\ /::::::::\\__\\ /:/__\\/\\:\\__\\" << endl;
  cout << "            " << "\\:\\/:/  /   \\:\\  \\ /:/  / \\:\\~~\\~~\\/__/ \\:\\  \\ /:/  /" << endl;
  cout << "            " << " \\::/__/     \\:\\  /:/  /   \\:\\  \\        \\:\\  /:/  / " << endl;
  cout << "            " << "  \\:\\  \\      \\:\\/:/  /     \\:\\  \\        \\:\\/:/  /  " << endl;
  cout << "            " << "   \\:\\__\\      \\::/  /       \\:\\__\\        \\::/  /   " << endl;
  cout << "            " << "    \\/__/       \\/__/         \\/__/         \\/__/    " << endl;

  cout << "                         " << "     ___           ___     " << endl;
  cout << "                         " << "    /\\  \\         /\\  \\ " << endl;
  cout << "                         " << "   /::\\  \\        \\:\\  \\ " << endl;
  cout << "                         " << "  /:/\\:\\  \\        \\:\\  \\ " << endl;
  cout << "                         " << " /:/  \\:\\  \\   _____\\:\\  \\ " << endl;
  cout << "                         " << "/:/__/ \\:\\__\\ /::::::::\\__\\ " << endl;
  cout << "                         " << "\\:\\  \\ /:/  / \\:\\~~\\~~\\/__/ " << endl;
  cout << "                         " << " \\:\\  /:/  /   \\:\\  \\ " << endl;
  cout << "                         " << "  \\:\\/:/  /     \\:\\  \\ " << endl;
  cout << "                         " << "   \\::/  /       \\:\\__\\ " << endl;
  cout << "                         " << "    \\/__/         \\/__/ " << endl;

  cout << "\n";

  cout << "                               " << "\033[93mH - How To Play\033[0m" << endl;
  cout << "                                 " << "\033[93mC - Credits\033[0m" << endl;

  cout << "                           " << "\033[1;31mPress Enter To Play Game\033[0m\n";
}

void howToPlay() {

  // cout << "hello there this is the how to play screen!" << endl;
  // cout << "For the leftside player hit W and S to go up and down." << endl;
  // cout << "For the right side player hit P and L to go up and down." << endl;
  // cout << "First person to score 3 points wins the game!" << endl;
  // cout << "You can press enter at anytime to start playing the game" << endl;
  clearScreen();
  clearScreen();
  cout << "       " << "  8   8                  \"\"8\"\"         8\"\"\"\"8 " << endl;
  cout << "       " << "  8   8 eeeee e   e  e     8   eeeee   8    8 e     eeeee e    e" << endl;
  cout << "       " << "  8eee8 8  88 8   8  8     8e  8  88   8eeee8 8     8   8 8    8" << endl;
  cout << "       " << "  88  8 8   8 8e  8  8     88  8   8   88     8e    8eee8 8eeee8" << endl;
  cout << "       " << "  88  8 8   8 88  8  8     88  8   8   88     88    88  8   88" << endl;
  cout << "       " << "  88  8 8eee8 88ee8ee8     88  8eee8   88     88eee 88  8   88" << endl;

  cout << "  " << "============================================================================" << endl;
  cout << " \033[1;93mThis game is formatted for a 80 x 27 terminal. For optimal use, please resize.\033[0m" << endl;
  cout << "\n";

  cout << "           " << "  +-+-+-+-+ +-+-+-+-+" << "               " <<   "+-+-+-+-+-+ +-+-+-+-+" << endl;
  cout << "           " << "  |L|e|f|t| |S|i|d|e|" << "               " <<   "|R|i|g|h|t| |S|i|d|e|" << endl;
  cout << "           " << "  +-+-+-+-+ +-+-+-+-+" << "               " <<   "+-+-+-+-+-+ +-+-+-+-+" << endl;

  cout << "      " << "   ____  " << "                   " << "          " << "   ____    " << "       " << endl;
  cout << "      " << "  ||W || " << "   Press W to      " << "          " << "  ||P ||   " << "   Press P to      " << endl;
  cout << "      " << "  ||__|| " << "     go up.        " << "          " << "  ||__||   " << "     go up.        " << endl;
  cout << "      " << "  |/__\\|" << "                   " << "          " << "   |/__\\| " << "       " << endl;

  cout << "      " << "   ____  " << "                   " << "          " << "   ____    " << "       " << endl;
  cout << "      " << "  ||S || " << "   Press S to      " << "          " << "  ||L ||   " << "   Press L to      " << endl;
  cout << "      " << "  ||__|| " << "     go down.      " << "          " << "  ||__||   " << "     go down.        " << endl;
  cout << "      " << "  |/__\\|" << "                   " << "          " << "   |/__\\| " << "       " << endl;

  cout << "\n";

  cout << "               " << "\033[1;91mFirst person to get a score of 3 will win the game!\033[0m" << endl;

  cout << "\n";

  cout << "          " << "B - Start Screen" << "     " << "\033[1;91mEnter - Play the Game\033[0m" << "      " << "C - Credits" << endl;

  cout << "\n";

}

void credits()
{
  clearScreen();

  cout << "                     " << "\033[1;255m         .8.           ,o888888o.      \033[0m" << endl;
  cout << "                     " << "\033[1;255m        .888.         8888     `88.    \033[0m" << endl;
  cout << "                     " << "\033[1;255m       :88888.     ,8 8888       `8.   \033[0m" << endl;
  cout << "                     " << "\033[1;255m      . `88888.    88 8888             \033[0m" << endl;
  cout << "                     " << "\033[0;35m     .8. `88888.   88 8888             \033[0m" << endl;
  cout << "                     " << "\033[0;35m    .8`8. `88888.  88 8888             \033[0m" << endl;
  cout << "                     " << "\033[0;35m   .8' `8. `88888. 88 8888             \033[0m" << endl;
  cout << "                     " << "\033[0;34m  .8'   `8. `88888.`8 8888       .8'   \033[0m" << endl;
  cout << "                     " << "\033[0;34m .888888888. `88888.  8888     ,88'    \033[0m" << endl;
  cout << "                     " << "\033[0;34m.8'       `8. `88888.  `8888888P'      \033[0m" << endl;

  cout << "        " << "\033[1;97m ______                __              __   __                     \033[0m" << endl;
  cout << "        " << "\033[1;97m|   __ \\.----.-----.--|  |.--.--.----.|  |_|__|.-----.-----.-----.\033[0m" << endl;
  cout << "        " << "\033[1;97m|    __/|   _|  _  |  _  ||  |  |  __||   _|  ||  _  |     |__ --|\033[0m" << endl;
  cout << "        " << "\033[1;97m|___|   |__| |_____|_____||_____|____||____|__||_____|__|__|_____|\033[0m" << endl;

  cout << "\n\n\n";

  for (int count = 0; count < 5; count++){

    if (count == 0){
      usleep(3000000);
      // cout << "Lead Programmers" << endl;
      cout << "                         " << "+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+-+" << endl;
      cout << "                         " << "|L|e|a|d| |P|r|o|g|r|a|m|m|e|r|s|" << endl;
      cout << "                         " << "+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+-+" << endl;
    }
    if (count == 1) {
      usleep(2000000);
      cout << "                                     " << "Cody Davis" << endl;
    }
    if (count == 2){
      usleep(2000000);
      cout << "                                    " << "Angela Tante" << endl;
    }
    if (count == 3) {
      usleep(3000000);
      cout << "\n\n";
      cout << "                              " << "Hope you enjoy the game!" << endl;
    }
    if (count == 4) {
      usleep(3000000);
      startScreen();
    }
  }
}

void endScreen(bool leftPlayer, bool rightPlayer)
{
  clearScreen();

  cout << "  " << "\033[1;31m @@@@@@@@  @@@@@@  @@@@@@@@@@  @@@@@@@@   @@@@@@  @@@  @@@ @@@@@@@@ @@@@@@@ \033[0m" << endl;
  cout << "  " << "\033[1;31m@@@@@@@@@ @@@@@@@@ @@@@@@@@@@@ @@@@@@@@  @@@@@@@@ @@@  @@@ @@@@@@@@ @@@@@@@@\033[0m" << endl;
  cout << "  " << "\033[1;31m!@@       @@!  @@@ @@! @@! @@! @@!       @@!  @@@ @@!  @@@ @@!      @@!  @@@\033[0m" << endl;
  cout << "  " << "\033[1;31m!@!       !@!  @!@ !@! !@! !@! !@!       !@!  @!@ !@!  @!@ !@!      !@!  @!@\033[0m" << endl;
  cout << "  " << "\033[1;31m!@! @!@!@ @!@!@!@! @!! !!@ @!@ @!!!:!    @!@  !@! @!@  !@! @!!!:!   @!@!!@! \033[0m" << endl;
  cout << "  " << "\033[1;31m!!! !!@!! !!!@!!!! !@!  !  !@! !!!!!:    !@!  !!! !@!  !!! !!!!!:   !!@!@!  \033[0m" << endl;
  cout << "  " << "\033[1;31m:!!   !!: !!:  !!! !!:     !!: !!:       !!:  !!! :!:  !!: !!:      !!: :!! \033[0m" << endl;
  cout << "  " << "\033[1;31m:!:   !:: :!:  !:! :!:     :!: :!:       :!:  !:!  ::!!:!  :!:      :!:  !:!\033[0m" << endl;
  cout << "  " << "\033[1;31m ::: :::: ::   ::: :::     ::   :: ::::  ::::: ::   ::::    :: :::: ::   :::\033[0m" << endl;
  cout << "  " << "\033[1;31m :: :: :   :   : :  :      :   : :: ::    : :  :     :     : :: ::   :   : :\033[0m" << endl;

  cout << "\n\n\n";

  if (leftPlayer) {
    cout << "                                " << "\033[1;93mLeft Player Won!\033[0m" << endl;
  } else if (rightPlayer) {
    cout << "                              " << "\033[1;93mRight Player Won!\033[0m" << endl;
  } else {
    cout << "                                  " << "\033[1;93mIt's a Draw!\033[0m" << endl;
  }

  cout << "\n\n\n";
  // cout << "                             " << "\033[1;97mThanks for Playing!\033[0m" << endl;

  cout << "\n\n\n\n";

}

//  ____
// ||W ||
// ||__||
// |/__\|

//  ____
// ||S ||
// ||__||
// |/__\|

//  ____
// ||P ||
// ||__||
// |/__\|

//  ____
// ||L ||
// ||__||
// |/__\|

// 8   8                  ""8""         8""""8
// 8   8 eeeee e   e  e     8   eeeee   8    8 e     eeeee e    e
// 8eee8 8  88 8   8  8     8e  8  88   8eeee8 8     8   8 8    8
// 88  8 8   8 8e  8  8     88  8   8   88     8e    8eee8 8eeee8
// 88  8 8   8 88  8  8     88  8   8   88     88    88  8   88
// 88  8 8eee8 88ee8ee8     88  8eee8   88     88eee 88  8   88



//  _   _                 _____       ____  _
// | | | | _____      __ |_   _|__   |  _ \| | __ _ _   _
// | |_| |/ _ \ \ /\ / /   | |/ _ \  | |_) | |/ _` | | | |
// |  _  | (_) \ V  V /    | | (_) | |  __/| | (_| | |_| |
// |_| |_|\___/ \_/\_/     |_|\___/  |_|   |_|\__,_|\__, |
//                                                  |___/

 //  __  __     ______     __     __        ______   ______        ______   __         ______     __  __
 // /\ \_\ \   /\  __ \   /\ \  _ \ \      /\__  _\ /\  __ \      /\  == \ /\ \       /\  __ \   /\ \_\ \
 // \ \  __ \  \ \ \/\ \  \ \ \/ ".\ \     \/_/\ \/ \ \ \/\ \     \ \  _-/ \ \ \____  \ \  __ \  \ \____ \
 //  \ \_\ \_\  \ \_____\  \ \__/".~\_\       \ \_\  \ \_____\     \ \_\    \ \_____\  \ \_\ \_\  \/\_____\
 //   \/_/\/_/   \/_____/   \/_/   \/_/        \/_/   \/_____/      \/_/     \/_____/   \/_/\/_/   \/_____/


 //  @@@@@@@@   @@@@@@   @@@@@@@@@@   @@@@@@@@      @@@@@@   @@@  @@@  @@@@@@@@  @@@@@@@
 // @@@@@@@@@  @@@@@@@@  @@@@@@@@@@@  @@@@@@@@     @@@@@@@@  @@@  @@@  @@@@@@@@  @@@@@@@@
 // !@@        @@!  @@@  @@! @@! @@!  @@!          @@!  @@@  @@!  @@@  @@!       @@!  @@@
 // !@!        !@!  @!@  !@! !@! !@!  !@!          !@!  @!@  !@!  @!@  !@!       !@!  @!@
 // !@! @!@!@  @!@!@!@!  @!! !!@ @!@  @!!!:!       @!@  !@!  @!@  !@!  @!!!:!    @!@!!@!
 // !!! !!@!!  !!!@!!!!  !@!   ! !@!  !!!!!:       !@!  !!!  !@!  !!!  !!!!!:    !!@!@!
 // :!!   !!:  !!:  !!!  !!:     !!:  !!:          !!:  !!!  :!:  !!:  !!:       !!: :!!
 // :!:   !::  :!:  !:!  :!:     :!:  :!:          :!:  !:!   ::!!:!   :!:       :!:  !:!
 //  ::: ::::  ::   :::  :::     ::    :: ::::     ::::: ::    ::::     :: ::::  ::   :::
 //  :: :: :    :   : :   :      :    : :: ::       : :  :      :      : :: ::    :   : :
 //


