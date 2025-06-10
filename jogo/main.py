import pygame
import sys
from jogo import Game, show_winner, show_rules, show_credits
from menu_test import main_menu

def run_game(display, clock, vs_computer=False):
    """Função para executar o jogo principal"""
    game = Game(vs_computer=vs_computer)
    
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    return 'menu'  # Retorna ao menu com ESC
                    
            if event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == 1:  # Botão esquerdo do mouse
                    pos = pygame.mouse.get_pos()
                    if pos[0] < 600:  # Verifica se o clique foi no tabuleiro
                        game.evaluate_click(pos)
        
        # Verifica se é o turno do computador
        if vs_computer and game._current_player_char == game.computer_player:
            if game.ai_move_timer and pygame.time.get_ticks() >= game.ai_move_timer:
                game.computer_move()
            elif not game.ai_move_timer:
                game.computer_move()
        
        # Desenha o jogo
        display.fill((54, 54, 54))  # BG_COLOR
        game.draw()
        
        # Verifica se o jogo terminou
        winner = game.check_winner()
        if winner is not None:
            # Mostra a tela de vitória e espera pela ação do usuário
            return show_winner(winner, display)
        
        pygame.display.update()
        clock.tick(60)
        
        # Verifica se o jogo terminou
        winner = game.check_winner()
        if winner is not None:
            show_winner(winner)
            pygame.time.wait(2000)  # Pequena pausa antes de voltar ao menu
            running = False
        
        pygame.display.update()
        clock.tick(60)

def main():
    pygame.init()
    WIDTH, HEIGHT = 800, 600
    display = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption('Jogo de Damas')
    clock = pygame.time.Clock()

    while True:
        choice = main_menu()
        
        if choice == "2players":
            result = run_game(display, clock, vs_computer=False)
            if result == 'quit':
                pygame.quit()
                sys.exit()
                
        elif choice == "vscomp":
            result = run_game(display, clock, vs_computer=True)
            if result == 'quit':
                pygame.quit()
                sys.exit()
                
        elif choice == "rules":
            result = show_rules()
            if result == 'quit':
                pygame.quit()
                sys.exit()
                
        elif choice == "credits":
            result = show_credits()
            if result == 'quit':
                pygame.quit()
                sys.exit()
                
        elif choice == "quit":
            pygame.quit()
            sys.exit()

if __name__ == "__main__":
    main()