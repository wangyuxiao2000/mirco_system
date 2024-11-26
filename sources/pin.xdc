# 25MHz 晶振时钟
set_property -dict {PACKAGE_PIN AJ32 IOSTANDARD LVCMOS18} [get_ports clk_25m]

# SW2 复位按钮
set_property -dict {PACKAGE_PIN AK29 IOSTANDARD LVCMOS18} [get_ports resetn]

# UART
set_property -dict {PACKAGE_PIN AG31 IOSTANDARD LVCMOS18} [get_ports tx]
set_property -dict {PACKAGE_PIN AF30 IOSTANDARD LVCMOS18} [get_ports rx]

# 未使用引脚
set_property SEVERITY {Warning} [get_drc_checks NSTD-1]
set_property SEVERITY {Warning} [get_drc_checks RTSTAT-1]
set_property SEVERITY {Warning} [get_drc_checks UCIO-1]