from datetime import datetime
from zoneinfo import ZoneInfo

ISRAEL_TZ = ZoneInfo("Asia/Jerusalem")

now = datetime.now(ISRAEL_TZ)

print("Snoopy Clock Test")
print("-----------------")
print(f"Time: {now.strftime('%H:%M')}")
print(f"Date: {now.strftime('%a %d %b')}")
print(f"Timezone: {now.tzname()}")
print(f"UTC offset: {now.utcoffset()}")