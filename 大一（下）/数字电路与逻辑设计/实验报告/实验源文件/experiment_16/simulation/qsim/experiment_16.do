onerror {exit -code 1}
vlib work
vlog -work work experiment_16.vo
vlog -work work Waveform_BCS.vwf.vt
vsim -novopt -c -t 1ps -L cycloneiii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.Buzzer_Clock_Simulation_vlg_vec_tst -voptargs="+acc"
vcd file -direction experiment_16.msim.vcd
vcd add -internal Buzzer_Clock_Simulation_vlg_vec_tst/*
vcd add -internal Buzzer_Clock_Simulation_vlg_vec_tst/i1/*
run -all
quit -f
