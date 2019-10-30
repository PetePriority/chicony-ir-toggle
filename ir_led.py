import os
import struct
from fcntl import ioctl
import ctypes

UVCIOC_CTRL_QUERY = 0xC0107521
UVC_SET_CUR = 0x01

class uvc_ctrl_query(ctypes.Structure):
    _fields_ = [
        ("unit", ctypes.c_uint8),
        ("selector", ctypes.c_uint8),
        ("query", ctypes.c_uint8),
        ("size", ctypes.c_uint16),
        ("data", ctypes.POINTER(ctypes.c_uint8)),
    ]

with open("/dev/video2", "w") as device:
    unit = 0x0e
    selector = 0x0e
    query = UVC_SET_CUR
    size = 2
    value = bytearray([0x00, 0x00])

    u8_array = ctypes.c_uint8 * len(value)

    data = uvc_ctrl_query(unit, selector, query, size, u8_array.from_buffer(value))

    libc = ctypes.CDLL('libc.so.6')

    fd = os.open("/dev/video2", os.O_WRONLY)
    libc.ioctl(fd, UVCIOC_CTRL_QUERY, ctypes.byref(data))
    os.close(fd)