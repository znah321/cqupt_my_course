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

-- DATE "05/13/2020 19:46:32"

-- 
-- Device: Altera EP3C16Q240C8 Package PQFP240
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY ALTERA;
LIBRARY CYCLONEIII;
LIBRARY IEEE;
USE ALTERA.ALTERA_PRIMITIVES_COMPONENTS.ALL;
USE CYCLONEIII.CYCLONEIII_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	D_trigger IS
    PORT (
	Q : OUT std_logic;
	CLRN : IN std_logic;
	CP : IN std_logic;
	D : IN std_logic;
	PRN : IN std_logic
	);
END D_trigger;

-- Design Ports Information
-- Q	=>  Location: PIN_63,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- PRN	=>  Location: PIN_230,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- CLRN	=>  Location: PIN_238,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D	=>  Location: PIN_237,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- CP	=>  Location: PIN_22,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF D_trigger IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_Q : std_logic;
SIGNAL ww_CLRN : std_logic;
SIGNAL ww_CP : std_logic;
SIGNAL ww_D : std_logic;
SIGNAL ww_PRN : std_logic;
SIGNAL \Q~output_o\ : std_logic;
SIGNAL \CLRN~input_o\ : std_logic;
SIGNAL \PRN~input_o\ : std_logic;
SIGNAL \inst~1_combout\ : std_logic;
SIGNAL \CP~input_o\ : std_logic;
SIGNAL \D~input_o\ : std_logic;
SIGNAL \inst~3_combout\ : std_logic;
SIGNAL \inst~0_combout\ : std_logic;
SIGNAL \inst~_emulated_q\ : std_logic;
SIGNAL \inst~2_combout\ : std_logic;
SIGNAL \ALT_INV_inst~0_combout\ : std_logic;

BEGIN

Q <= ww_Q;
ww_CLRN <= CLRN;
ww_CP <= CP;
ww_D <= D;
ww_PRN <= PRN;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_inst~0_combout\ <= NOT \inst~0_combout\;

-- Location: IOOBUF_X3_Y0_N9
\Q~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst~2_combout\,
	devoe => ww_devoe,
	o => \Q~output_o\);

-- Location: IOIBUF_X1_Y29_N15
\CLRN~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_CLRN,
	o => \CLRN~input_o\);

-- Location: IOIBUF_X7_Y29_N22
\PRN~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_PRN,
	o => \PRN~input_o\);

-- Location: LCCOMB_X1_Y21_N6
\inst~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst~1_combout\ = (\CLRN~input_o\ & ((\inst~1_combout\) # (!\PRN~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110000001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \CLRN~input_o\,
	datac => \PRN~input_o\,
	datad => \inst~1_combout\,
	combout => \inst~1_combout\);

-- Location: IOIBUF_X0_Y21_N22
\CP~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_CP,
	o => \CP~input_o\);

-- Location: IOIBUF_X1_Y29_N8
\D~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_D,
	o => \D~input_o\);

-- Location: LCCOMB_X1_Y21_N0
\inst~3\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst~3_combout\ = \inst~1_combout\ $ (\D~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst~1_combout\,
	datac => \D~input_o\,
	combout => \inst~3_combout\);

-- Location: LCCOMB_X1_Y21_N4
\inst~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst~0_combout\ = (!\PRN~input_o\) # (!\CLRN~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011111100111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \CLRN~input_o\,
	datac => \PRN~input_o\,
	combout => \inst~0_combout\);

-- Location: FF_X1_Y21_N1
\inst~_emulated\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CP~input_o\,
	d => \inst~3_combout\,
	clrn => \ALT_INV_inst~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst~_emulated_q\);

-- Location: LCCOMB_X1_Y21_N10
\inst~2\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst~2_combout\ = (\CLRN~input_o\ & ((\inst~1_combout\ $ (\inst~_emulated_q\)) # (!\PRN~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst~1_combout\,
	datab => \inst~_emulated_q\,
	datac => \PRN~input_o\,
	datad => \CLRN~input_o\,
	combout => \inst~2_combout\);

ww_Q <= \Q~output_o\;
END structure;


