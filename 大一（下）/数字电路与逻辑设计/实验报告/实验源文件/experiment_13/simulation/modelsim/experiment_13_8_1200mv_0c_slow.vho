-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 13.1.0 Build 162 10/23/2013 SJ Full Version"

-- DATE "06/03/2020 20:06:55"

-- 
-- Device: Altera EP3C16Q240C8 Package PQFP240
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIII;
LIBRARY IEEE;
USE CYCLONEIII.CYCLONEIII_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	lab_1 IS
    PORT (
	H : OUT std_logic_vector(6 DOWNTO 0);
	A3 : IN std_logic;
	A2 : IN std_logic;
	A1 : IN std_logic;
	A0 : IN std_logic
	);
END lab_1;

-- Design Ports Information
-- H[6]	=>  Location: PIN_46,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- H[5]	=>  Location: PIN_45,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- H[4]	=>  Location: PIN_103,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- H[3]	=>  Location: PIN_199,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- H[2]	=>  Location: PIN_98,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- H[1]	=>  Location: PIN_56,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- H[0]	=>  Location: PIN_232,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A2	=>  Location: PIN_151,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A0	=>  Location: PIN_152,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A1	=>  Location: PIN_134,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A3	=>  Location: PIN_108,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF lab_1 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_H : std_logic_vector(6 DOWNTO 0);
SIGNAL ww_A3 : std_logic;
SIGNAL ww_A2 : std_logic;
SIGNAL ww_A1 : std_logic;
SIGNAL ww_A0 : std_logic;
SIGNAL \H[6]~output_o\ : std_logic;
SIGNAL \H[5]~output_o\ : std_logic;
SIGNAL \H[4]~output_o\ : std_logic;
SIGNAL \H[3]~output_o\ : std_logic;
SIGNAL \H[2]~output_o\ : std_logic;
SIGNAL \H[1]~output_o\ : std_logic;
SIGNAL \H[0]~output_o\ : std_logic;
SIGNAL \A0~input_o\ : std_logic;
SIGNAL \A3~input_o\ : std_logic;
SIGNAL \A1~input_o\ : std_logic;
SIGNAL \A2~input_o\ : std_logic;
SIGNAL \inst36~0_combout\ : std_logic;
SIGNAL \inst32~0_combout\ : std_logic;
SIGNAL \inst27~0_combout\ : std_logic;
SIGNAL \inst22~0_combout\ : std_logic;
SIGNAL \inst17~0_combout\ : std_logic;
SIGNAL \inst13~0_combout\ : std_logic;
SIGNAL \inst8~0_combout\ : std_logic;

BEGIN

H <= ww_H;
ww_A3 <= A3;
ww_A2 <= A2;
ww_A1 <= A1;
ww_A0 <= A0;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X0_Y6_N16
\H[6]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst36~0_combout\,
	devoe => ww_devoe,
	o => \H[6]~output_o\);

-- Location: IOOBUF_X0_Y9_N2
\H[5]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst32~0_combout\,
	devoe => ww_devoe,
	o => \H[5]~output_o\);

-- Location: IOOBUF_X28_Y0_N30
\H[4]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst27~0_combout\,
	devoe => ww_devoe,
	o => \H[4]~output_o\);

-- Location: IOOBUF_X26_Y29_N2
\H[3]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst22~0_combout\,
	devoe => ww_devoe,
	o => \H[3]~output_o\);

-- Location: IOOBUF_X26_Y0_N30
\H[2]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst17~0_combout\,
	devoe => ww_devoe,
	o => \H[2]~output_o\);

-- Location: IOOBUF_X0_Y3_N2
\H[1]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst13~0_combout\,
	devoe => ww_devoe,
	o => \H[1]~output_o\);

-- Location: IOOBUF_X5_Y29_N2
\H[0]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst8~0_combout\,
	devoe => ww_devoe,
	o => \H[0]~output_o\);

-- Location: IOIBUF_X41_Y15_N1
\A0~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A0,
	o => \A0~input_o\);

-- Location: IOIBUF_X30_Y0_N8
\A3~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A3,
	o => \A3~input_o\);

-- Location: IOIBUF_X41_Y8_N1
\A1~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A1,
	o => \A1~input_o\);

-- Location: IOIBUF_X41_Y15_N8
\A2~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A2,
	o => \A2~input_o\);

-- Location: LCCOMB_X30_Y7_N0
\inst36~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst36~0_combout\ = (\A0~input_o\ & (!\A3~input_o\ & (\A1~input_o\ $ (!\A2~input_o\)))) # (!\A0~input_o\ & (!\A1~input_o\ & (\A3~input_o\ $ (!\A2~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010010000000011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A0~input_o\,
	datab => \A3~input_o\,
	datac => \A1~input_o\,
	datad => \A2~input_o\,
	combout => \inst36~0_combout\);

-- Location: LCCOMB_X30_Y7_N26
\inst32~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst32~0_combout\ = (\A0~input_o\ & (\A3~input_o\ $ (((\A1~input_o\) # (!\A2~input_o\))))) # (!\A0~input_o\ & (!\A3~input_o\ & (\A1~input_o\ & !\A2~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010100000110010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A0~input_o\,
	datab => \A3~input_o\,
	datac => \A1~input_o\,
	datad => \A2~input_o\,
	combout => \inst32~0_combout\);

-- Location: LCCOMB_X30_Y7_N4
\inst27~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst27~0_combout\ = (\A1~input_o\ & (\A0~input_o\ & (!\A3~input_o\))) # (!\A1~input_o\ & ((\A2~input_o\ & ((!\A3~input_o\))) # (!\A2~input_o\ & (\A0~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010001100101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A0~input_o\,
	datab => \A3~input_o\,
	datac => \A1~input_o\,
	datad => \A2~input_o\,
	combout => \inst27~0_combout\);

-- Location: LCCOMB_X30_Y7_N30
\inst22~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst22~0_combout\ = (\A1~input_o\ & ((\A0~input_o\ & ((\A2~input_o\))) # (!\A0~input_o\ & (\A3~input_o\ & !\A2~input_o\)))) # (!\A1~input_o\ & (!\A3~input_o\ & (\A0~input_o\ $ (\A2~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000101000010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A0~input_o\,
	datab => \A3~input_o\,
	datac => \A1~input_o\,
	datad => \A2~input_o\,
	combout => \inst22~0_combout\);

-- Location: LCCOMB_X30_Y7_N24
\inst17~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst17~0_combout\ = (\A3~input_o\ & (\A2~input_o\ & ((!\A1~input_o\) # (!\A0~input_o\)))) # (!\A3~input_o\ & (!\A0~input_o\ & (!\A1~input_o\ & !\A2~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100110000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A0~input_o\,
	datab => \A3~input_o\,
	datac => \A1~input_o\,
	datad => \A2~input_o\,
	combout => \inst17~0_combout\);

-- Location: LCCOMB_X30_Y7_N10
\inst13~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst13~0_combout\ = (\A3~input_o\ & ((\A0~input_o\ & (\A1~input_o\)) # (!\A0~input_o\ & ((\A2~input_o\))))) # (!\A3~input_o\ & (\A2~input_o\ & (\A0~input_o\ $ (\A1~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101011010000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A0~input_o\,
	datab => \A3~input_o\,
	datac => \A1~input_o\,
	datad => \A2~input_o\,
	combout => \inst13~0_combout\);

-- Location: LCCOMB_X30_Y7_N28
\inst8~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst8~0_combout\ = (\A3~input_o\ & (\A0~input_o\ & (\A1~input_o\ $ (\A2~input_o\)))) # (!\A3~input_o\ & (!\A1~input_o\ & (\A0~input_o\ $ (\A2~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000100110000010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A0~input_o\,
	datab => \A3~input_o\,
	datac => \A1~input_o\,
	datad => \A2~input_o\,
	combout => \inst8~0_combout\);

ww_H(6) <= \H[6]~output_o\;

ww_H(5) <= \H[5]~output_o\;

ww_H(4) <= \H[4]~output_o\;

ww_H(3) <= \H[3]~output_o\;

ww_H(2) <= \H[2]~output_o\;

ww_H(1) <= \H[1]~output_o\;

ww_H(0) <= \H[0]~output_o\;
END structure;


