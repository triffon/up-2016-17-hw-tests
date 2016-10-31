@echo off

echo ~~~~~~~~~~~~ Tests started ~~~~~~~~~~~~~

for /l %%i in (1,1,10) do (
	if not exist fn*_prob%%i_*.exe (
		echo ========= fnXXXXX_prob%%i_CC.exe not found! =========
	) else (
		echo ======= Testing program %%i started ======
		echo.
		for %%t in (%%i?.test) do (
			echo -------- Running test %%t ---------
			echo.
			echo ^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^> Input ^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>
			type %%t
			echo.
			echo ^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>
			echo.
			prog%%i.exe < %%t >%%t.out
			echo ^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^< Output ^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<
			type %%t.out
			echo.
			echo ^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<^<
			echo.
			fc %%t.out %%t.ans >nul
			if errorlevel 1 (
				echo !!!!!!!!!!!!!!!! ERROR !!!!!!!!!!!!!!!!!
				echo ########### Expected output ############
				type %%t.ans
				echo.
				echo ########################################
			) else (
				echo ++++++++++++++++++ OK ++++++++++++++++++
			)
			echo.
			echo -------- Test %%t finished ---------
			pause
		)
		echo ====== Testing program %%i finished ======
		pause
	)
	echo.
)

echo ~~~~~~~~~~~~ Tests finished ~~~~~~~~~~~~
pause
