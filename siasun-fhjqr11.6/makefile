EXE = main
SRC = main.c ./CJSON/cJSON_User.c ./CJSON/cJSON.c ./AGV/Reproducer_Lamplight.c ./AGV/Motion_Ctrl.c ./AGV/Agv_Control.c ./AGV/agv.c ./Thread_Pool/Thread_Pool.c ./CNS_MGS_160S/CNS_MGS_160S.c ./CNS_RFID_1S/CNS_RFID_1S.c ./UART/UART.c ./CAN/can.c ./FD123_CA_000/FD123_CA_000.c ./HC_SuK043_C/HC_SuK043_C.c ./SPC_SDIO_1616/SPC_SDIO_1616.c ./Timer/Timer.c ./TCP/TCP.c 
HEADER_PATH = -I"/home/siasunhebo/ggm/siasun-fhjqr9.30"  -I./CJSON/ -I./AGV/ -I./Thread_Pool/ -I./h/ -I./CNS_MGS_160S/ -I./TCP/ -I./CNS_RFID_1S -I./CAN/ -I./FD123_CA_000/ -I./HC_SuK043_C/ -I./SPC_SDIO_1616/ -I./Timer -I./UART -I./Timer 

$(EXE):
	$(CC) $(HEADER_PATH) $(SRC) -o $(EXE) -g -lpthread -lrt -lm


clean:
	rm -rf main *.o
