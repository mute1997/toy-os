global syshandler
extern syscall_handler

syshandler:
  call syscall_handler
  iret
