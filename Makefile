
all: cmake_build

cmake_build:
	mkdir -p build
	cd build && cmake ..
	$(MAKE) -C build

clean:
	rm -rf build
	rm -f EventDistrib

install: cmake_build
	install -m 755 ./build/EventDistrib ./EventDistrib

.PHONY: all cmake_build clean install
