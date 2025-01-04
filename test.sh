echo "-------- Error1: no argument -----------"
valgrind --leak-check=full -q ./so_long

echo "-------- Error2: too many arguments -----------"
valgrind --leak-check=full -q ./so_long map1.ber maps/e_empty.ber

echo "-------- Error3: empty map -----------"
valgrind --leak-check=full -q ./so_long maps/e_empty.ber

echo "-------- Error4:invalid character -----------"
valgrind --leak-check=full -q ./so_long maps/e_invalid_character.ber

echo "-------- Error5: multiple players -----------"
valgrind --leak-check=full -q ./so_long maps/e_multiple_players.ber

echo "-------- Error6: no collectible -----------"
valgrind --leak-check=full -q ./so_long maps/e_no_collectible.ber

echo "-------- Error7: no exit -----------"
valgrind --leak-check=full -q ./so_long maps/e_no_exit.ber

echo "-------- Error8: no player -----------"
valgrind --leak-check=full -q ./so_long maps/e_no_player.ber

echo "-------- Error9: not closed -----------"
valgrind --leak-check=full -q ./so_long maps/e_not_closed.ber

echo "-------- Error10: not rectangle -----------"
valgrind --leak-check=full -q ./so_long maps/e_not_rectangle.ber

echo "-------- Error11: unreachable -----------"
valgrind --leak-check=full -q ./so_long maps/e_unreachable.ber

# echo "-------- Playable map-----------"
# valgrind --leak-check=full -q ./so_long maps/map1.ber
