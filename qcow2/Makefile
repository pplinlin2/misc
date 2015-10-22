BASE := base.qcow2
WRAP := wrap.qcow2
IMGA := A.qcow2
IMGB := B.qcow2
IMGC := C.qcow2

GUEST := 'Guest sees'
C1 := '\e[33m'
C2 := '\e[34m'
E := '\e[0m'
QEMU := qemu-system-arm
INSTALL := sudo apt-get install

all:
	@echo 'usage:'
	@echo '  make check'
	@echo '  make exp'
	@echo '  make clean'

exp:
	@echo -e $(C1)'Create a new file'$(E)
	qemu-img create -f qcow2 $(BASE) 1M
	@echo -e $(C1)'Write some guest data'$(E)
	qemu-io -c "write $$((512*1024 - 512)) $$((65*1024))" $(BASE)
	@echo -e $(C1)'Create an internal snapshot'$(E)
	qemu-img snapshot -c one $(BASE)
	@echo -e $(C1)'Write more guest data'$(E)
	qemu-io -c "write $$((512*1024 - 64*1024 + 512)) 512)" $(BASE)
	@echo -e $(C1)'Create an external snapshot'$(E)
	qemu-img create -f qcow2 -b $(BASE) $(WRAP)
	@echo -e $(C1)'Write even more guest data'$(E)
	qemu-io -c "write -P 0xff $$((512*1024-63*1024)) $$((64*1024))" $(WRAP)
	#hexdump -C $(WRAP) -s 0x00040000 | head

abc:
	qemu-img create -f qcow2 $(IMGA) 512K
	qemu-io -c "write -P 0x41 $$((256*1024)) $$((4*64*1024))" $(IMGA)
	qemu-img create -f qcow2 -b $(IMGA) $(IMGB)
	qemu-io -c "write -P 0x42 $$((128*1024)) $$((2*64*1024))" $(IMGB)
	qemu-io -c "write -P 0x42 $$((384*1024)) $$((2*64*1024))" $(IMGB)
	qemu-img create -f qcow2 -b $(IMGB) $(IMGC)
	qemu-io -c "write -P 0x43 $$((64*1024)) $$((64*1024))" $(IMGC)
	qemu-io -c "write -P 0x43 $$((192*1024)) $$((64*1024))" $(IMGC)
	qemu-io -c "write -P 0x43 $$((320*1024)) $$((64*1024))" $(IMGC)
	qemu-io -c "write -P 0x43 $$((448*1024)) $$((64*1024))" $(IMGC)
	@echo -e $(C1)'         Contents   '$(GUEST)$(E)
	@echo -e $(C1)$(IMGA)': ---- AAAA  ---- AAAA'$(E)
	@echo -e $(C1)$(IMGB)': --BB --BB  --BB AABB'$(E)
	@echo -e $(C1)$(IMGC)': -C-C -C-C  -CBC ACBC'$(E)
	#hexdump -C $(IMGA) -s 0x00040000 | head
	#hexdump -C $(IMGB) -s 0x00040000 | head
	#hexdump -C $(IMGC) -s 0x00040000 | head

check:
	$(INSTALL) $(QEMU)
	@echo -e $(C2)'Ref: http://events.linuxfoundation.org/sites/events/files/slides/2015-qcow2-expanded.pdf'$(E)

clean:
	-rm $(BASE) $(WRAP) $(IMGA) $(IMGB) $(IMGC)
