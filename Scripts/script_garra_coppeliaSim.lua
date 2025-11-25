function sysCall_init()
    base = sim.getObject('.')

    gearLeft = sim.getObject('/gear_left_Corpo1')
    armLeft  = sim.getObject('/arm_left_Corpo1')
    jawLeft  = sim.getObject('/jaw_left_Corpo1')

    gearRight = sim.getObject('/gear_right_Corpo1')
    armRight  = sim.getObject('/arm_right_Corpo1')
    jawRight  = sim.getObject('/jaw_right_Corpo1')

    blade = sim.getObject('/Componente12_Corpo1')

    bladeOriginalMatrix = sim.getObjectMatrix(blade, jawLeft)

    estado = 1
    angle = 0
    bladeAngle = 0

    angleMin = 5 * math.pi/180
end

function sysCall_actuation()
    dt = sim.getSimulationTimeStep()

    local velocidade = 0.02 * math.pi/180   

    if estado == 1 then
        angle = angle + velocidade
        if angle >= 20 * math.pi/180 then
            angle = 20 * math.pi/180
            estado = 2
        end
    end

    if estado == 2 then
        angle = angle - velocidade
        if angle <= angleMin then
            angle = angleMin
            estado = 3
        end
    end

    sim.setObjectOrientation(jawLeft,  base, {0,0, -angle})
    sim.setObjectOrientation(armLeft,  base, {0,0, -angle * 0.6})
    sim.setObjectOrientation(jawRight, base, {0,0,  angle})
    sim.setObjectOrientation(armRight, base, {0,0,  angle * 0.6})

    sim.setObjectOrientation(gearLeft,  base, {0,0, 0})
    sim.setObjectOrientation(gearRight, base, {0,0, 0})

    if estado == 3 then
        local bladeSpeed = 0.4
        bladeAngle = bladeAngle + bladeSpeed * dt
    end

    local rot = sim.buildMatrix({0,0,0}, {0, bladeAngle, 0})
    local result = sim.multiplyMatrices(bladeOriginalMatrix, rot)
    sim.setObjectMatrix(blade, jawLeft, result)
end
