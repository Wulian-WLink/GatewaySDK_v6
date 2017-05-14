TARGET = test
CC_MIPS = mipsel-openwrt-linux-g++

INCLUDE = -I/usr/local/OpenWrt-SDK-ramips-for-redhat-i686-gcc-4.8-linaro_uClibc-0.9.33.2/staging_dir/target-mipsel_24kec+dsp_uClibc-0.9.33.2/usr/include \
		  -I/usr/local/OpenWrt-SDK-ramips-for-redhat-i686-gcc-4.8-linaro_uClibc-0.9.33.2/staging_dir/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_uClibc-0.9.33.2/usr/include \
		  -L/home/xjz/youqh/GatewaySDK_v6/include \
		  -I/home/xjz/mipsel/curl2/include \
		  -I/home/xjz/mips_lib/jsoncpp/include

LIBFLAG = -L. -Ltarget/mips_libs -L/home/xjz/youqh/youqh_v6/third_party/lib\
		  -L/usr/local/OpenWrt-SDK-ramips-for-redhat-i686-gcc-4.8-linaro_uClibc-0.9.33.2/staging_dir/target-mipsel_24kec+dsp_uClibc-0.9.33.2/usr/lib \
		  -lcommfun -ldci -ljsoncpp -lboost_thread -lboost_system -lboost_atomic -lmosquitto -lcurl -lssl -lcrypto -lpolarssl -lcares
		  
all: 
	$(CC_MIPS) $(LIBFLAG) example/test_main.cpp -o test 

.PHONY: clean
clean:
	-rm -f -f $(TARGET)
